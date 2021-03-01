/*
Maximum Sum In Subarray

You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤
50000 ). A query is defined as follows: Query(x,y) = Max { a[i]+a[i+1]+...+a[j]
; x ≤ i ≤ j ≤ y }. Given M queries, your program must output the results of
these queries.

Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.

Output
Your program should output the results of the M queries, one
query per line.

Sample Input:
3
-1 2 3
1
1 2

Sample Output:
2
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

typedef struct quad {
    int maxSum;
    int sum;
    int prefixSum;
    int suffixSum;
} quad;

void buildTree(vt<int>& arr, vt<quad>& tree, int start, int end, int treeNode) {
    if (start == end) {
        quad q;
        q.maxSum = arr[start];
        q.sum = arr[start];
        q.prefixSum = arr[start];
        q.suffixSum = arr[start];
        tree[treeNode] = q;
        return;
    }

    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

    quad q;
    quad left = tree[2 * treeNode];
    quad right = tree[2 * treeNode + 1];

    q.sum = left.sum + right.sum;
    q.prefixSum = max(left.prefixSum, left.sum + right.prefixSum);
    q.suffixSum = max(right.suffixSum, right.sum + left.suffixSum);
    q.maxSum =
        max(max(max(left.maxSum, right.maxSum),
                max(left.sum + right.prefixSum, right.sum + left.suffixSum)),
            (left.suffixSum + right.prefixSum));

    tree[treeNode] = q;
}

void updateTree(vt<int>& arr, vt<quad>& tree, int start, int end, int treeNode,
                int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        quad q;
        q.sum = val;
        q.prefixSum = val;
        q.suffixSum = val;
        q.maxSum = val;
        tree[treeNode] = q;
        return;
    }

    int mid = (start + end) / 2;

    if (idx > mid) {
        updateTree(arr, tree, mid + 1, end, 2 * treeNode + 1, idx, val);
    } else {
        updateTree(arr, tree, start, mid, 2 * treeNode, idx, val);
    }

    quad q;
    quad left = tree[2 * treeNode];
    quad right = tree[2 * treeNode + 1];

    q.sum = left.sum + right.sum;
    q.prefixSum = max(left.prefixSum, left.sum + right.prefixSum);
    q.suffixSum = max(right.suffixSum, right.sum + left.suffixSum);
    q.maxSum =
        max(max(max(left.maxSum, right.maxSum),
                max(left.sum + right.prefixSum, right.sum + left.suffixSum)),
            (left.suffixSum + right.prefixSum));

    tree[treeNode] = q;
}

quad query(vt<quad>& tree, int start, int end, int treeNode, int left,
           int right) {
    // Completely oustide the range
    if (start > right || end < left) {
        quad q;
        q.maxSum = INT_MIN;
        q.sum = INT_MIN;
        q.suffixSum = INT_MIN;
        q.prefixSum = INT_MIN;
        return q;
    }

    // Completely inside the range
    if (start >= left && end <= right) {
        return tree[treeNode];
    }

    // Partially inside and partially outside
    int mid = (start + end) / 2;
    quad ans1 = query(tree, start, mid, 2 * treeNode, left, right);
    quad ans2 = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);

    quad q;
    q.sum = ans1.sum + ans2.sum;
    q.prefixSum = max(ans1.prefixSum, ans1.sum + ans2.prefixSum);
    q.suffixSum = max(ans2.suffixSum, ans2.sum + ans1.suffixSum);
    q.maxSum =
        max(max(max(ans1.maxSum, ans2.maxSum),
                max(ans1.sum + ans2.prefixSum, ans2.sum + ans1.suffixSum)),
            (ans1.suffixSum + ans2.prefixSum));
    return q;
}

void solve() {
    int n;
    cin >> n;
    vt<int> arr(n);
    cin >> arr;

    vt<quad> tree(4 * n);

    buildTree(arr, tree, 0, n - 1, 1);

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        cout << query(tree, 0, n - 1, 1, l, r).maxSum << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    FOR(tt, t) solve();
    return 0;
}