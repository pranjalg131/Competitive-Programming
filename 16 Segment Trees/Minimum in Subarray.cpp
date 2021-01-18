/*
Minimum In SubArray

Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.

Input:
First line of the test case contains two integers, N and Q, size of array A and
number of queries. Second line contains N space separated integers, elements of
A. Next Q lines contain one of the two queries.

Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].

Contraints:
1≤N,Q,y≤10^5
1≤l,r,x≤N

Sample Input :
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5

Sample Output :
1
1
2
1
*/

#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); }

string to_string(const char& ch) { return "'" + string(1, ch) + "'"; }

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

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << " " << to_string(H);
    debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

#define int int64_t
#define ar array<int, 2>
#define pii pair<int, int>
#define pb push_back
#define vt vector
#define For(i, n) for (int i = 0; i < n; i++)
#define Rev(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, n) for (int i = 1; i <= n; i++)
#define REV(i, n) for (int i = n; i >= 1; i--)
#define Rep(i, a, b) for (int i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

template <typename T>
using mxpq = priority_queue<T>;
template <typename T>
using mnpq = priority_queue<T, vt<T>, greater<T>>;

template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
    in >> a.first >> a.second;
    return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& a) {
    out << a.first << " " << a.second;
    return out;
}
template <class A, size_t S>
istream& operator>>(istream& in, array<A, S>& a) {
    for (A& x : a) in >> x;
    return in;
}
template <class A, size_t S>
ostream& operator<<(ostream& out, array<A, S>& a) {
    bool f = false;
    for (A& x : a) {
        if (f) out << " ";
        out << x;
        f = true;
    }
    return out;
}
template <typename T>
istream& operator>>(istream& in, vt<T>& a) {
    for (T& x : a) in >> x;
    return in;
}
template <typename T>
ostream& operator<<(ostream& out, vt<T>& a) {
    bool f = false;
    for (T& x : a) {
        if (f) out << " ";
        out << x;
        f = true;
    }
    out << '\n';
    return out;
}
void out(bool ok, bool cap = true) {
    if (cap)
        cout << (ok ? "YES" : "NO") << '\n';
    else
        cout << (ok ? "Yes" : "No") << '\n';
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
    if (b > a) a = b;
    return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
    if (b < a) a = b;
    return a;
}

const int mod = 1e9 + 7;
const int INF = 1e18L + 5;
const int N = 2e5 + 5;

void buildTree(vt<int>& arr, vt<int>& tree, int start, int end, int treeNode) {
    if (start == end) {
        tree[treeNode] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

    tree[treeNode] = min(tree[2 * treeNode], tree[2 * treeNode + 1]);
}

void updateTree(vt<int>& arr, vt<int>& tree, int start, int end, int treeNode,
                int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        tree[treeNode] = val;
        return;
    }

    int mid = (start + end) / 2;

    if (idx > mid) {
        updateTree(arr, tree, mid + 1, end, 2 * treeNode + 1, idx, val);
    } else {
        updateTree(arr, tree, start, mid, 2 * treeNode, idx, val);
    }

    tree[treeNode] = min(tree[2 * treeNode], tree[2 * treeNode + 1]);
}

int query(vt<int>& tree, int start, int end, int treeNode, int left,
          int right) {
    // Completely oustide the range
    if (start > right || end < left) {
        return INT_MAX;
    }

    // Completely inside the range
    if (start >= left && end <= right) {
        return tree[treeNode];
    }

    // Partially inside and partially outside
    int mid = (start + end) / 2;
    int ans1 = query(tree, start, mid, 2 * treeNode, left, right);
    int ans2 = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);

    return min(ans1, ans2);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vt<int> arr(n);
    cin >> arr;

    vt<int> tree(4 * n);
    buildTree(arr, tree, 0, n - 1, 1);

    while (q--) {
        char ch;
        int l, r;
        cin >> ch >> l >> r;
        l--;
        r--;

        if (ch == 'q') {
            cout << query(tree, 0, n - 1, 1, l, r) << "\n";
        }

        if (ch == 'u') {
            updateTree(arr, tree, 0, n - 1, 1, l, r + 1);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    FOR(tt, t) solve();
    return 0;
}