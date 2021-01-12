/*
Miser Man

Jack is a wise and miser man. Always tries to save his money.
One day, he wants to go from city A to city B. Between A and B, there are N
number of cities(including B and excluding A) and in each city there are M buses
numbered from 1 to M. And the fare of each bus is different. Means for all N*M
busses, fare (K) may be different or same. Now Jack has to go from city A to
city B following these conditions:
1. At every city, he has to change the bus.
2. And he can switch to only those buses which have number either equal or 1
less or 1 greater to the previous. You are to help Jack to go from A to B by
spending the minimum amount of money.

N, M, K <= 100.

Input
Line 1:    N M
Line 2:    NxM Grid

Each row lists the fares the M busses to go form the current city to the next
city.

Output
Single Line containing the minimum amount of fare that Jack has to give.

Sample Input
5 5
1  3  1  2  6
10 2  5  4  15
10 9  6  7  1
2  7  1  5  3
8  2  6  1  9
Sample Output
10
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vt<vt<int>> arr(n, vt<int>(m));
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cin >> arr[i][j];
        }
    }

    vt<vt<int>> dp(n, vt<int>(m));

    for (int j = 0; j < dp[0].size(); j++) {
        dp[0][j] = arr[0][j];
    }

    for (int i = 1; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            int ans1, ans2, ans3;
            if (j - 1 < 0) {
                ans1 = INT_MAX;

            } else {
                ans1 = dp[i - 1][j - 1];
            }
            if (j + 1 >= dp[i].size()) {
                ans2 = INT_MAX;

            } else {
                ans2 = dp[i - 1][j + 1];
            }

            ans3 = dp[i - 1][j];

            dp[i][j] = arr[i][j] + min(ans3, min(ans2, ans1));
        }
    }

    int ans = INT_MAX;

    for (int j = 0; j < dp[n - 1].size(); j++) {
        if (ans > dp[n - 1][j]) ans = dp[n - 1][j];
    }

    cout << ans << "\n";

    return 0;
}