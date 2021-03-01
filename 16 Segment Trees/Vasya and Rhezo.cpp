/*
Vasya vs Rhezo

Queen Vasya is preparing for a war against Rhezo. She has N warriors in total
arranged in a line. Let us number the warriors by numbers from 1 to N. She will
fight Rhezo's army for Q days, and each day she can choose only one warrior. For
each warrior, we know 2 values associated with him, let us call these A and B.
Each day Vasya can choose her warrior from a range Li to Ri, she must choose the
warrior with maximum A value. If there is more than 1 warrior having the same
maximum A value, she chooses the warrior with minimum B value. If still there is
more than 1 warrior with same maximum A value and same minimum B value, she
chooses the one with lower index in line. You being the hand of Queen Vasya,
need to help her in choosing the warrior for each day.

Input:
First line contains a single integer N, denoting the number of warriors Queen
Vasya has. Second line contains N space separated integers Ai. Third line
contains N space separated integers Bi. Next line contains a single integer Q,
denoting the number of days Queen Vasya chooses a warrior. Each of the next Q
lines contains 2 integers Li and Ri.

Output:
For each Li and Ri, print the index of the warrior that Queen Vasya should
choose.

Constraints:
1≤ N,Q ≤10^6
1≤ Ai,Bi ≤10^9
1≤Li≤Ri

Sample Input
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5

Sample Output
2
2
4
5
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

struct tNode {
    int A;
    int B;
    int idx;
};

void buildTree(vt<pii>& arr, vt<tNode>& tree, int start, int end,
               int treeNode) {
    if (start == end) {
        tree[treeNode].A = arr[start].first;
        tree[treeNode].B = arr[start].second;
        tree[treeNode].idx = start;
        return;
    }

    int mid = (start + end) / 2;
    int leftChild = 2 * treeNode, rightChild = 2 * treeNode + 1;
    buildTree(arr, tree, start, mid, leftChild);
    buildTree(arr, tree, mid + 1, end, rightChild);

    if (tree[leftChild].A > tree[rightChild].A) {
        tree[treeNode].A = tree[leftChild].A;
        tree[treeNode].B = tree[leftChild].B;
        tree[treeNode].idx = tree[leftChild].idx;

    } else {
        tree[treeNode].A = tree[rightChild].A;
        tree[treeNode].B = tree[rightChild].B;
        tree[treeNode].idx = tree[rightChild].idx;
    }

    if (tree[leftChild].A == tree[rightChild].A) {
        if (tree[leftChild].B < tree[rightChild].B) {
            tree[treeNode].A = tree[leftChild].A;
            tree[treeNode].B = tree[leftChild].B;
            tree[treeNode].idx = tree[leftChild].idx;

        } else {
            tree[treeNode].A = tree[rightChild].A;
            tree[treeNode].B = tree[rightChild].B;
            tree[treeNode].idx = tree[rightChild].idx;
        }
    }

    if (tree[leftChild].A == tree[rightChild].A &&
        tree[leftChild].B == tree[rightChild].B) {
        tree[treeNode].A = tree[leftChild].A;
        tree[treeNode].B = tree[leftChild].B;
        tree[treeNode].idx = tree[leftChild].idx;
    }
}

tNode query(vt<tNode>& tree, int start, int end, int treeNode, int left,
            int right) {
    // Completely oustide the range
    if (start > right || end < left) {
        tNode t;
        t.A = INT_MIN;
        t.B = INT_MAX;
        t.idx = INT_MAX;
        return t;
    }

    // Completely inside the range
    if (start >= left && end <= right) {
        return tree[treeNode];
    }

    // Partially inside and partially outside
    int mid = (start + end) / 2;
    tNode ans1 = query(tree, start, mid, 2 * treeNode, left, right);
    tNode ans2 = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);

    tNode ans;

    if (ans1.A > ans2.A) {
        ans.A = ans1.A;
        ans.B = ans1.B;
        ans.idx = ans1.idx;

    } else {
        ans.A = ans2.A;
        ans.B = ans2.B;
        ans.idx = ans2.idx;
    }

    if (ans1.A == ans2.A) {
        if (ans1.B < ans2.B) {
            ans.A = ans1.A;
            ans.B = ans1.B;
            ans.idx = ans1.idx;

        } else {
            ans.A = ans2.A;
            ans.B = ans2.B;
            ans.idx = ans2.idx;
        }
    }

    if (ans1.A == ans2.A && ans1.B == ans2.B) {
        if (ans1.idx < ans2.idx) {
            ans.A = ans1.A;
            ans.B = ans1.B;
            ans.idx = ans1.idx;

        } else {
            ans.A = ans2.A;
            ans.B = ans2.B;
            ans.idx = ans2.idx;
        }
    }

    return ans;
}

void solve() {
    int n, q;
    cin >> n;
    vt<pii> arr(n);
    For(i, n) cin >> arr[i].first;
    For(i, n) cin >> arr[i].second;

    vt<tNode> tree(4 * n);

    buildTree(arr, tree, 0, n - 1, 1);

    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        cout << query(tree, 0, n - 1, 1, l, r).idx + 1 << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    FOR(tt, t) solve();
    return 0;
}