/*
Alyona and Spreadsheet

During the lesson small girl Alyona works with one famous spreadsheet computer
program and learns how to edit tables. Now she has a table filled with integers.
The table consists of n rows and m columns. By ai, j we will denote the integer
located at the i-th row and the j-th column. We say that the table is sorted in
non-decreasing order in the column j if ai, j ≤ ai + 1, j for all i from 1 to
n - 1. Teacher gave Alyona k tasks. For each of the tasks two integers l and r
are given and Alyona has to answer the following question: if one keeps the rows
from l to r inclusive and deletes all others, will the table be sorted in
non-decreasing order in at least one column? Formally, does there exist such j
that ai, j ≤ ai + 1, j for all i from l to r - 1 inclusive. Alyona is too small
to deal with this task and asks you to help!

Input
The first line of the input contains two positive integers n and m
(1 ≤ n·m ≤ 100 000) — the number of rows and the number of columns in the table
respectively. Note that your are given a constraint that bound the product of
these two integers, i.e. the number of elements in the table.

Each of the following n lines contains m integers. The j-th integers in the i of
these lines stands for ai, j (1 ≤ ai, j ≤ 109).

The next line of the input contains an integer k (1 ≤ k ≤ 100 000) — the number
of task that teacher gave to Alyona.

The i-th of the next k lines contains two integers li and ri (1 ≤ li ≤ ri ≤ n).

Output
Print "Yes" to the i-th line of the output if the table consisting of rows from
li to ri inclusive is sorted in non-decreasing order in at least one column.
Otherwise, print "No".

Sample Input
5 4
1 2 3 5
3 1 3 2
4 5 2 3
5 5 3 2
4 4 3 4
6
1 1
2 5
4 5
3 5
1 3
1 5

Sample Output
Yes
No
Yes
Yes
Yes
No
*/

#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string &s) { return '"' + s + '"'; }

string to_string(const char *s) { return to_string((string)s); }

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
    for (const auto &x : v) {
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
        dp[0][j] = 0;
    }
    for (int i = 1; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            if (arr[i][j] >= arr[i - 1][j]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = i;
            }
        }
    }
    // dbg(dp);
    vt<int> row(n);

    for (int i = 0; i < dp.size(); i++) {
        int m = INT_MAX;
        for (int j = 0; j < dp[i].size(); j++) {
            if (dp[i][j] < m) {
                m = dp[i][j];
            }
        }
        row[i] = m;
    }

    // dbg(row);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (row[r] <= (l)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}