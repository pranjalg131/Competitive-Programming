/*
Maximum Pair Sum

You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5
). There are two types of operations and they are defined as follows:

Update:
This will be indicated in the input by a 'U' followed by space and then two
integers i and x. U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8. This operation sets the
value of A[i] to x.

Query:
This will be indicated in the input by a 'Q' followed by a single space and then
two integers i and j. Q x y, 1 ≤ x < y ≤ N. You must find i and j such that x ≤
i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum
A[i]+A[j].

Input
The first line of input consists of an integer N representing the length of the
sequence. Next line consists of N space separated integers A[i]. Next line
contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q
lines contain the operations.

Output
 Output the maximum sum mentioned above, in a separate line, for each Query.

Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5

Output:
7
9
11
12
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

void buildTree(vt<int>& arr, vt<pair<int, int>>& tree, int start, int end,
               int treeNode) {
    if (start == end) {
        pair<int, int> p = make_pair(arr[start], INT_MIN);
        tree[treeNode] = p;
        return;
    }

    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

    tree[treeNode].first =
        max(tree[2 * treeNode].first, tree[2 * treeNode + 1].first);
    tree[treeNode].second =
        min(max(tree[2 * treeNode].first, tree[2 * treeNode + 1].second),
            max(tree[2 * treeNode].second, tree[2 * treeNode + 1].first));
    return;
}

void updateTree(vt<int>& arr, vt<pair<int, int>>& tree, int start, int end,
                int treeNode, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        tree[treeNode].first = val;
        return;
    }

    int mid = (start + end) / 2;

    if (idx > mid) {
        updateTree(arr, tree, mid + 1, end, 2 * treeNode + 1, idx, val);
    } else {
        updateTree(arr, tree, start, mid, 2 * treeNode, idx, val);
    }

    tree[treeNode].first =
        max(tree[2 * treeNode].first, tree[2 * treeNode + 1].first);
    tree[treeNode].second =
        min(max(tree[2 * treeNode].first, tree[2 * treeNode + 1].second),
            max(tree[2 * treeNode].second, tree[2 * treeNode + 1].first));
}

pair<int, int> query(vt<pair<int, int>>& tree, int start, int end, int treeNode,
                     int left, int right) {
    // Completely oustide the range
    if (start > right || end < left) {
        pair<int, int> p = make_pair(INT_MIN, INT_MIN);
        return p;
    }

    // Completely inside the range
    if (start >= left && end <= right) {
        return tree[treeNode];
    }

    // Partially inside and partially outside
    int mid = (start + end) / 2;
    pair<int, int> ans1 = query(tree, start, mid, 2 * treeNode, left, right);
    pair<int, int> ans2 =
        query(tree, mid + 1, end, 2 * treeNode + 1, left, right);

    pair<int, int> finalAns;
    finalAns.first = max(ans1.first, ans2.first);
    finalAns.second =
        min(max(ans1.first, ans2.second), max(ans1.second, ans2.first));

    return finalAns;
}

void solve() {
    int n;
    cin >> n;
    vt<int> arr(n);
    cin >> arr;
    int q;
    cin >> q;

    vt<pair<int, int>> tree(3 * n);

    buildTree(arr, tree, 0, n - 1, 1);

    while (q--) {
        char ch;
        int l, r;

        cin >> ch;
        cin >> l >> r;
        l--;
        r--;

        if (ch == 'Q') {
            pair<int, int> ans = query(tree, 0, n - 1, 1, l, r);
            cout << ans.first + ans.second << "\n";
        }
        if (ch == 'U') {
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