/*
Trader Profit
Mike is a stock trader and makes a profit by buying and selling stocks. He buys
a stock at a lower price and sells it at a higher price to book a profit. He has
come to know the stock prices of a particular stock for n upcoming days in
future and wants to calculate the maximum profit by doing the right transactions
(single transaction = buying + selling). Can you help him maximize his profit?
Note: A transaction starts after the previous transaction has ended. Two
transactions can't overlap or run in parallel. The stock prices are given in the
form of an array A for n days. Given the stock prices and a positive integer k,
find and print the maximum profit Mike can make in at most k transactions.

Input Format
The first line of input contains an integer q denoting the number of queries.
The first line of each test case contains a positive integer k, denoting the
number of transactions. The second line of each test case contains a positive
integer n, denoting the length of the array A. The third line of each test case
contains n space-separated positive integers, denoting the prices of each day in
the array A.

Constraints
1<=q<=100
0<k<10
2<=n<=30
0<=elements of array A<=1000

Output Format
For each query print the maximum profit earned by Mike on a new line.

Sample Input
3
2
6
10 22 5 75 65 80
3
4
20 580 420 900
1
5
100 90 80 50 25

Sample Output
87
1040
0
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

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k >> n;
        vt<int> arr(n);
        for (int i = 0; i < arr.size(); i++) {
            cin >> arr[i];
        }

        vt<vt<int>> dp(k + 1, vt<int>(n, 0));

        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[i].size(); j++) {
                int curr = dp[i][j - 1];
                for (int p = 0; p < j; p++) {
                    int ans = dp[i - 1][p] + (arr[j] - arr[p]);
                    if (ans > curr) {
                        curr = ans;
                    }
                }
                dp[i][j] = curr;
            }
        }

        // dbg(dp);

        cout << dp[k][n - 1] << "\n";
    }

    return 0;
}