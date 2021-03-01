/*
2 vs 3

The fight for the best number in the globe is going to finally come to an
end.The top two contenders for the best number are number 2 and number 3.It's
the final the entire world was waiting for. Expectorates from all across the
globe came to witness the breath taking finals. The finals began in an
astonishing way.A common problem was set for both of them which included both
these number.The problem goes like this. Given a binary string (that is a string
consisting of only 0 and 1). They were supposed to perform two types of query on
the string.

Type 0: Given two indices l and r.Print the value of the binary string from l to
r modulo 3.

Type 1: Given an index l flip the value of that index if and only if the value
at that index is 0.

The problem proved to be a really tough one for both of them.Hours passed by but
neither of them could solve the problem.So both of them wants you to solve this
problem and then you get the right to choose the best number in the globe.

Input:
The first line contains N denoting the length of the binary string .
The second line contains the N length binary string.Third line contains the
integer Q indicating the number of queries to perform. This is followed up by Q
lines where each line contains a query.

Output:
For each query of Type 0 print the value modulo 3.

Constraints:
1<= N <=10^5
1<= Q <= 10^5
0 <= l <= r < N

Sample Input
5
10010
6
0 2 4
0 2 3
1 1
0 0 4
1 1
0 0 3

Sample Output
2
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

struct tNode {
    int ans;
    int bits;
};

vt<int> power(1e5 + 1);

void buildTree(vt<int>& arr, vt<tNode>& tree, int start, int end,
               int treeNode) {
    if (start == end) {
        tree[treeNode].ans = arr[start] % 3;
        tree[treeNode].bits = 1;
        return;
    }

    int mid = (start + end) / 2;
    int leftChild = 2 * treeNode, rightChild = 2 * treeNode + 1;
    buildTree(arr, tree, start, mid, leftChild);
    buildTree(arr, tree, mid + 1, end, rightChild);

    tree[treeNode].bits = tree[leftChild].bits + tree[rightChild].bits;
    // clang-format off
    tree[treeNode].ans =
        (tree[rightChild].ans +
         (tree[leftChild].ans * power[tree[rightChild].bits]) % 3
        ) % 3;
    // clang-format on
}

void updateTree(vt<int>& arr, vt<tNode>& tree, int start, int end, int treeNode,
                int idx) {
    if (start == end) {
        if (arr[idx] == 0) arr[idx] = 1;
        tree[treeNode].ans = arr[idx] % 3;
        return;
    }

    int mid = (start + end) / 2;
    int leftChild = 2 * treeNode, rightChild = 2 * treeNode + 1;

    if (idx > mid) {
        updateTree(arr, tree, mid + 1, end, rightChild, idx);
    } else {
        updateTree(arr, tree, start, mid, leftChild, idx);
    }

    tree[treeNode].bits = tree[leftChild].bits + tree[rightChild].bits;
    // clang-format off
    tree[treeNode].ans =
        (tree[rightChild].ans +
         (tree[leftChild].ans * power[end-mid]) % 3
        ) % 3;
    // clang-format on
}

tNode query(vt<tNode>& tree, int start, int end, int treeNode, int left,
            int right) {
    // Completely oustide the range
    if (start > right || end < left) {
        tNode t;
        t.ans = 0;
        t.bits = 0;
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

    ans.bits = ans1.bits + ans2.bits;
    // clang-format off
    ans.ans =
        (ans2.ans +
         (ans1.ans * power[right-mid]) % 3
        ) % 3;
    // clang-format on

    return ans;
}

void solve() {
    power[0] = 1;
    for (int i = 1; i < 1e5; i++) {
        power[i] = ((power[i - 1] % 3) * (2 % 3)) % 3;
    }

    int n, q;
    cin >> n;
    string s;
    cin >> s;

    vt<int> arr(n);
    For(i, n) arr[i] = s[i] - '0';

    vt<tNode> tree(3 * n);

    buildTree(arr, tree, 0, n - 1, 1);

    // dbg("Segment tree");
    // for (int i = 1; i < 3 * n; i++) {
    //     cout << "{ " << tree[i].ans << " " << tree[i].bits << " }, ";
    // }
    // cout << endl;

    cin >> q;
    while (q--) {
        int c, l, r;
        cin >> c;

        if (c == 0) {
            cin >> l >> r;
            l--;
            r--;  // 0 based indexing

            cout << query(tree, 0, n - 1, 1, l, r).ans << "\n";
        }

        if (c == 1) {
            cin >> l;
            l--;

            updateTree(arr, tree, 0, n - 1, 1, l);
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