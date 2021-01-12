/*
Charlie and Pilots

Charlie acquired airline transport company and to stay in business he needs to
lower the expenses by any means possible. There are N pilots working for his
company (N is even) and N/2 plane crews needs to be made. A plane crew consists
of two pilots - a captain and his assistant. A captain must be older than his
assistant. Each pilot has a contract granting him two possible salaries - one as
a captain and the other as an assistant. A captain's salary is larger than
assistant's for the same pilot. However, it is possible that an assistant has
larger salary than his captain. Write a program that will compute the minimal
amount of money Charlie needs to give for the pilots' salaries if he decides to
spend some time to make the optimal (i.e. the cheapest) arrangement of pilots in
crews.

Input
The first line of input contains integer N, 2 ≤ N ≤ 10,000, N is even, the
number of pilots working for the Charlie's company. The next N lines of input
contain pilots' salaries. The lines are sorted by pilot's age, the salaries of
the youngest pilot are given the first. Each of those N lines contains two
integers separated by a space character, X i Y, 1 ≤ Y < X ≤ 100,000, a salary as
a captain (X) and a salary as an assistant (Y).

Output
The first and only line of output should contain the minimal amount of money
Charlie needs to give for the pilots' salaries.

Sample Input
4
5000 3000
6000 2000
8000 1000
9000 6000

Sample Output
19000
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

ll getSal(int* assist, int* captain, int n, int x, vt<vt<ll>>& dp) {
    ll ans = 0;
    if (n == 0) return 0;

    if (dp[n][x] != -1) {
        return dp[n][x];
    }

    if (x == 0) {
        ans = assist[0] + getSal(assist + 1, captain + 1, n - 1, x + 1, dp);
    } else if (x == n) {
        ans = captain[0] + getSal(assist + 1, captain + 1, n - 1, x - 1, dp);
    } else {
        ans =
            min(assist[0] + getSal(assist + 1, captain + 1, n - 1, x + 1, dp),
                captain[0] + getSal(assist + 1, captain + 1, n - 1, x - 1, dp));
    }

    dp[n][x] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int assist[n], captain[n];
    for (int i = 0; i < n; i++) {
        cin >> captain[i] >> assist[i];
    }

    vt<vt<ll>> dp(n + 1, vt<ll>(n + 1, -1));

    ll sal = assist[0];
    ll ans = getSal(assist + 1, captain + 1, n - 1, 1, dp);

    cout << (sal + ans) << "\n";

    return 0;
}