/*
Square Brackets

You are given:
a positive integer n,
an integer k, 1<=k<=n,
an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.
What is the number of proper bracket expressions of length 2n with opening
brackets appearing in positions s1, s2,...,sk?

Illustration

Several proper bracket expressions:
[[]][[[]][]]
[[[][]]][][[]]
An improper bracket expression:
[[[][]]][]][[]]
There is exactly one proper expression of length 8 with opening brackets in
positions 2, 5 and 7.

Task
Write a program which for each data set from a sequence of several data sets:
1. reads integers n, k and an increasing sequence of k integers from input,
2. computes the number of proper bracket expressions of length 2n with opening
brackets appearing at positions s1,s2,...,sk,
3. writes the result to output.

Input
The first line of the input file contains one integer d, 1 <= d <= 10, which is
the number of data sets. The data sets follow. Each data set occupies two lines
of the input file. The first line contains two integers n and k separated by
single space, 1 <= n <= 19, 1 <= k <= n. The second line contains an increasing
sequence of k integers from the interval [1;2n] separated by single spaces.

Output
The i-th line of output should contain one integer - the number of proper
bracket expressions of length 2n with opening brackets appearing at positions
s1, s2,...,sk.

Sample Input
5
1 1
1
1 1
2
2 1
1
3 1
2
4 2
5 7
Sample Output
1
0
2
3
2
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

ll getAns(int n, int oc, int cc, vt<bool>& arr, vt<vt<ll>>& dp) {
    if (oc > n || cc > n) {
        return 0;
    }
    if (oc == n && cc == n) {
        return 1;
    }

    if (dp[oc][cc] != -1) {
        return dp[oc][cc];
    }

    ll ans;

    if (oc == cc || arr[oc + cc + 1]) {
        ans = getAns(n, oc + 1, cc, arr, dp);
    } else if (oc == n) {
        ans = getAns(n, oc, cc + 1, arr, dp);
    } else {
        ans = getAns(n, oc, cc + 1, arr, dp) + getAns(n, oc + 1, cc, arr, dp);
    }

    dp[oc][cc] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vt<bool> arr(2 * n + 5, false);
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            arr[x] = true;
        }

        vt<vt<ll>> dp(n + 3, vt<ll>(n + 3, -1));

        ll ans = getAns(n, 0, 0, arr, dp);

        cout << ans << "\n";
    }

    return 0;
}