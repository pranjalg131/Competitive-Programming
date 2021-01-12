/*
Shortest Subsequence

Gary has two string S and V. Now, Gary wants to know the length shortest
subsequence in S, which is not a subsequence in V. Note: The input data will be
such that there will always be a solution.

Input Format :
The first line of input contains a string, that denotes the value of S. The
following line contains a string, that denotes the value of V.

Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V

Constraints:
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second

Sample Input 1:
babab
babba
Sample Output 1:
3
Explanation:
"aab" is the shortest subsequence which is present in S and absent in V.
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
#define MAX 1005

const ll mod = 1e9L + 7;
const ll INF = 1e18L + 5;
const ll mxN = 2e5 + 1;

int getAns(string s1, string s2) {
    int m = s1.length(), n = s2.length();

    // declaring 2D array of m + 1 rows and
    // n + 1 columns dynamically
    int dp[m + 1][n + 1];

    // T string is empty
    for (int i = 0; i <= m; i++) dp[i][0] = 1;

    // S string is empty
    for (int i = 0; i <= n; i++) dp[0][i] = MAX;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            char ch = s1[i - 1];
            int k;
            for (k = j - 1; k >= 0; k--)
                if (s2[k] == ch) break;

            // char not present in T
            if (k == -1)
                dp[i][j] = 1;
            else
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][k] + 1);
        }
    }

    int ans = dp[m][n];
    if (ans >= MAX) ans = -1;

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    int ans = getAns(s1, s2);
    cout << ans << "\n";

    return 0;
}