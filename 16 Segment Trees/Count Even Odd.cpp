/*
Counting Even/Odd

Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his
intelligence.He gives him an array of N natural numbers and asks him to solve
the following queries:- Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.
Input:
First line of the input contains the number N. Next line contains N natural
numbers. Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y.

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.

Constraints:
1<=N,Q<=10^5
1<=l<=r<=N
0<=Ai<=10^9
1<=x<=N
0<=y<=10^9

Note:-
indexing starts from 1.

Sample Input
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
Sample Output
2
2
4
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

typedef struct tNode {
    int eCount;
    int oCount;
} tNode;

void buildTree(vt<int>& arr, vt<tNode>& tree, int start, int end,
               int treeNode) {
    if (start == end) {
        if (arr[start] & 1) {
            tree[treeNode].oCount++;
        } else {
            tree[treeNode].eCount++;
        }
        return;
    }

    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

    int leftChild = 2 * treeNode, rightChild = 2 * treeNode + 1;

    tree[treeNode].eCount = tree[leftChild].eCount + tree[rightChild].eCount;
    tree[treeNode].oCount = tree[leftChild].oCount + tree[rightChild].oCount;
}

void updateTree(vt<int>& arr, vt<tNode>& tree, int start, int end, int treeNode,
                int idx, int val) {
    if (start == end) {
        // To modify even and odd counts respectively
        if ((arr[idx] & 1) ^ (val & 1)) {
            // only works if one is odd and other is even and vice versa
            if (arr[idx] & 1) {
                tree[treeNode].oCount--;
                tree[treeNode].eCount++;
            }
            if (val & 1) {
                tree[treeNode].oCount++;
                tree[treeNode].eCount--;
            }
        }
        arr[idx] = val;

        return;
    }

    int mid = (start + end) / 2;

    if (idx > mid) {
        updateTree(arr, tree, mid + 1, end, 2 * treeNode + 1, idx, val);
    } else {
        updateTree(arr, tree, start, mid, 2 * treeNode, idx, val);
    }

    int leftChild = 2 * treeNode, rightChild = 2 * treeNode + 1;

    tree[treeNode].oCount = tree[leftChild].oCount + tree[rightChild].oCount;
    tree[treeNode].eCount = tree[leftChild].eCount + tree[rightChild].eCount;
}

tNode query(vt<tNode>& tree, int start, int end, int treeNode, int left,
            int right) {
    // Completely oustide the range
    if (start > right || end < left) {
        tNode t;
        t.eCount = 0;
        t.oCount = 0;
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
    ans.eCount = ans1.eCount + ans2.eCount;
    ans.oCount = ans1.oCount + ans2.oCount;
    return ans;
}

void solve() {
    int n, q;
    cin >> n;
    vt<int> arr(n);
    cin >> arr;

    tNode t;
    t.eCount = 0;
    t.oCount = 0;

    vt<tNode> tree(3 * n, t);
    buildTree(arr, tree, 0, n - 1, 1);

    cin >> q;

    while (q--) {
        int c, l, r;
        cin >> c >> l >> r;
        l--;
        r--;  // 0 based indexing

        if (c == 0) {
            updateTree(arr, tree, 0, n - 1, 1, l,
                       r + 1);  // r-- happened for 0 based indexing
        }
        if (c == 1) {
            cout << query(tree, 0, n - 1, 1, l, r).eCount << "\n";
        }
        if (c == 2) {
            cout << query(tree, 0, n - 1, 1, l, r).oCount << "\n";
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