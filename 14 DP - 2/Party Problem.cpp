/*
PARTY - Problem

You just received another bill which you cannot pay because you lack the money.
Unfortunately, this is not the first time to happen, and now you decide to
investigate the cause of your constant monetary shortness. The reason is quite
obvious: the lion's share of your money routinely disappears at the entrance of
party localities. You make up your mind to solve the problem where it arises,
namely at the parties themselves. You introduce a limit for your party budget
and try to have the most possible fun with regard to this limit. You inquire
beforehand about the entrance fee to each party and estimate how much fun you
might have there. The list is readily compiled, but how do you actually pick the
parties that give you the most fun and do not exceed your budget? Write a
program which finds this optimal set of parties that offer the most fun. Keep in
mind that your budget need not necessarily be reached exactly. Achieve the
highest possible fun level, and do not spend more money than is absolutely
necessary.

Input
The first line of the input specifies your party budget and the number n of
parties. The following n lines contain two numbers each. The first number
indicates the entrance fee of each party. Parties cost between 5 and 25 francs.
The second number indicates the amount of fun of each party, given as an integer
number ranging from 0 to 10.

The budget will not exceed 500 and there will be at most 100 parties. All
numbers are separated by a single space.

There are many test cases. Input ends with 0 0.

Output
For each test case your program must output the sum of the entrance fees and the
sum of all fun values of an optimal solution. Both numbers must be separated by
a single space.

Sample Input
50 10
12 3
15 8
16 9
16 6
10 2
21 9
18 4
12 4
17 8
18 9

50 10
13 8
19 10
16 8
12 9
10 2
12 8
13 5
15 5
11 7
16 2

0 0

Sample Output
49 26
48 32
*/

#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto& x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
           to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
           to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

#define CERR cout

void debug_out() { CERR << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    CERR << " " << to_string(H);
    debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define dbg(...) CERR << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

#define ar array<ll, 2>
#define ll long long
#define in insert
#define pb push_back
#define vt vector
#define P_Q(x) priority_queue<x>
#define p_q(x) priority_queue<x, vector<x>, greater<x>>
#define For(i, n) for (ll i = 0; i < n; i++)
#define Rev(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, n) for (ll i = 1; i <= n; i++)
#define REV(i, n) for (ll i = n; i >= 1; i--)
#define Rep(i, a, b) for (ll i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const ll mod = 1e9L + 7;
const ll INF = 1e18L + 5;
const ll mxN = 2e5 + 1;

pair<int, int> maxFun(vt<int> fees, vt<int> fun, int n, int k) {
    vt<pair<int, int>> dp1(k + 1, make_pair(0, 0)), dp2(k + 1, make_pair(0, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < dp2.size(); j++) {
            if (j - fees[i] < 0) {
                dp2[j] = dp1[j];
            } else {
                pair<int, int> option1 =
                    make_pair(fees[i] + dp1[j - fees[i]].first,
                              fun[i] + dp1[j - fees[i]].second);

                if (dp1[j].second > option1.second) {
                    dp2[j] = dp1[j];
                } else if (dp1[j].second == option1.second) {
                    if (dp1[j].first < option1.first) {
                        dp2[j] = dp1[j];
                    } else {
                        dp2[j] = option1;
                    }
                } else {
                    dp2[j] = option1;
                }
            }
        }
        dp1 = dp2;
        dp2 = vt<pair<int, int>>(k + 1, make_pair(0, 0));
    }

    return dp1[k];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    cin >> k >> n;
    while (k != 0 && n != 0) {
        vt<int> fees(n), fun(n);
        for (int i = 0; i < n; i++) {
            cin >> fees[i] >> fun[i];
        }

        pair<int, int> ans = maxFun(fees, fun, n, k);

        cout << ans.first << " " << ans.second << "\n";

        cin >> k >> n;
    }
    return 0;
}