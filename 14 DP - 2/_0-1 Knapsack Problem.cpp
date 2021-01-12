/*
Knapsnack - Problem
A thief is robbing a store and can carry a maximal weight of W into his
knapsack. There are N items and ith item weighs wi and is of value vi.
Considering the constraints of maximum weight that knapsack can carry, you have
to find and return the maximum value that thief can generate by stealing items.

Note
Space complexity should be O(W).

Input Format :
The first line contains an integers, that denote the value of N. The following
line contains N space separated integers, that denote the values of weight of
items. The following line contains N space separated integers, that denote the
values associated with the items. The following line contains an integer that
denote the value of W. W denotes maximum weight that thief can carry.

Output Format :
The first and only line of output contains the maximum value that thief can
generate, as described in the task.

Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Time Limit: 1 second

Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
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

int knapsnack(vt<int> weights, vt<int> values, int n, int k) {
    vt<int> dp1(k + 1, 0), dp2(k + 1, 0);

    for (int i = 0; i < weights.size(); i++) {
        for (int j = 1; j < dp1.size(); j++) {
            if ((j - weights[i]) < 0) {
                dp2[j] = dp1[j];
            } else {
                dp2[j] = max(values[i] + dp1[j - weights[i]], dp1[j]);
            }
        }
        dp1 = dp2;
        dp2 = vt<int>(k + 1, 0);
    }

    return dp1[k];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n;
    vt<int> weights(n), values(n);
    for (int i = 0; i < weights.size(); i++) {
        cin >> weights[i];
    }
    for (int i = 0; i < values.size(); i++) {
        cin >> values[i];
    }
    cin >> k;
    int ans = knapsnack(weights, values, n, k);

    cout << ans << "\n";
    return 0;
}