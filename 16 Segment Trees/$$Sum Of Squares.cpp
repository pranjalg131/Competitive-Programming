/*
Sum Of Squares

Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see
here, for example) allows one to compute sums over a range in O(lg(n)), and
update ranges in O(lg(n)) as well. In this problem you will compute something
much harder: The sum of squares over a range with range updates of 2 types: 1)
increment in a range 2) set all numbers the same in a range.

Input
There will be T (T <= 25) test cases in the input file. First line of the input
contains two positive integers, N (N <= 100,000) and Q (Q <= 100,000). The next
line contains N integers, each at most 1000. Each of the next Q lines starts
with a number, which indicates the type of operation:

2 st nd -- return the sum of the squares of the numbers with indices in [st, nd]
{i.e., from st to nd inclusive} (1 <= st <= nd <= N).

1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <=
N, and -1,000 <= x <= 1,000).

0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <=
N, and -1,000 <= x <= 1,000).

Output
For each test case output the “Case <caseno>:” in the first line and from the
second line output the sum of squares for each operation of type 2. Intermediate
overflow will not occur with proper use of 64-bit signed integer.

Input:
2
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
1 1
1
2 1 1

Output:
Case 1:
30
7
13
Case 2:
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

#define tNode pair<int, int>
#define lNode pair<int, int>
#define sqSum first
#define sum second
#define type first
#define val second

void buildTree(vector<int>& arr, vector<tNode>& tree, int start, int end,
               int treeNode) {
    if (start == end) {
        tree[treeNode].sqSum = arr[start] * arr[start];
        tree[treeNode].sum = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    int leftChild = 2 * treeNode, rightChild = 2 * treeNode + 1;
    buildTree(arr, tree, start, mid, leftChild);
    buildTree(arr, tree, mid + 1, end, rightChild);

    tree[treeNode].sqSum = tree[leftChild].sqSum + tree[rightChild].sqSum;
    tree[treeNode].sum = tree[leftChild].sum + tree[rightChild].sum;
}

void lazyUpdateTree(vector<tNode>& tree, vector<lNode>& lazy, int start,
                    int end, int treeNode, int left, int right, int type,
                    int val) {
    if (start > end) {
        return;
    }
    // dbg("before", start, end, lazy[treeNode], tree[treeNode]);

    if (lazy[treeNode].type != 2) {
        if (lazy[treeNode].type == 1) {
            int count = end - start + 1;
            int a = count * lazy[treeNode].val * lazy[treeNode].val;
            int b = 2 * lazy[treeNode].val * tree[treeNode].sum;
            tree[treeNode].sqSum += a + b;
            tree[treeNode].sum += count * lazy[treeNode].val;
        }

        if (lazy[treeNode].type == 0) {
            int count = end - start + 1;
            tree[treeNode].sqSum =
                count * lazy[treeNode].val * lazy[treeNode].val;
            tree[treeNode].sum = count * lazy[treeNode].val;
        }

        if (start < end) {  // If children exist then only.
            tNode& p = lazy[treeNode];
            for (int child : {2 * treeNode, 2 * treeNode + 1}) {
                tNode& c = lazy[child];
                if (p.type == 0) {
                    c.val = p.val;
                    c.type = 0;
                } else if (p.type == 1) {
                    if (c.type == 2) {
                        c.type = 1;
                    }
                    c.val += p.val;
                }
            }
        }
        lazy[treeNode].type = 2;
        lazy[treeNode].val = 0;  // reset the lazy tree for current node
    }

    // No overlap
    if (start > right || end < left) {
        return;
    }

    // Complete overlap
    if (left <= start && end <= right) {
        // dbg("complete");
        // First changing the current node according to the query type
        if (type == 1) {
            int count = end - start + 1;
            int a = count * val * val;
            int b = 2 * val * tree[treeNode].sum;
            tree[treeNode].sqSum += a + b;
            tree[treeNode].sum += count * val;
        }

        if (type == 0) {
            int count = end - start + 1;
            tree[treeNode].sqSum = count * val * val;
            tree[treeNode].sum = count * val;
        }

        if (start < end) {
            // If children exist then update their status in lazy tree.
            for (int child : {2 * treeNode, 2 * treeNode + 1}) {
                tNode& c = lazy[child];
                if (type == 0) {
                    c.val = val;
                    c.type = 0;
                } else if (type == 1) {
                    if (c.type == 2) {
                        c.type = 1;
                    }
                    c.val += val;
                }
            }
        }

        // dbg("after", start, end, lazy[treeNode], tree[treeNode]);

        return;
    }

    // Partial Overlap
    int mid = (start + end) / 2;
    int leftChild = 2 * treeNode, rightChild = 2 * treeNode + 1;
    lazyUpdateTree(tree, lazy, start, mid, leftChild, left, right, type, val);
    lazyUpdateTree(tree, lazy, mid + 1, end, rightChild, left, right, type,
                   val);

    tree[treeNode].sqSum = tree[leftChild].sqSum + tree[rightChild].sqSum;
    tree[treeNode].sum = tree[leftChild].sum + tree[rightChild].sum;
}

tNode lazyQuery(vector<tNode>& tree, vector<lNode>& lazy, int start, int end,
                int treeNode, int left, int right) {
    // Firstly Updating from the lazy tree.
    if (start > end) {
        tNode t;
        t.sqSum = 0;
        t.sum = 0;
        return t;
    }

    if (lazy[treeNode].type != 2) {
        if (lazy[treeNode].type == 1) {
            int count = end - start + 1;
            int a = count * lazy[treeNode].val * lazy[treeNode].val;
            int b = 2 * lazy[treeNode].val * tree[treeNode].sum;
            tree[treeNode].sqSum += a + b;
            tree[treeNode].sum += count * lazy[treeNode].val;
        }

        if (lazy[treeNode].type == 0) {
            int count = end - start + 1;
            tree[treeNode].sqSum =
                count * lazy[treeNode].val * lazy[treeNode].val;
            tree[treeNode].sum = count * lazy[treeNode].val;
        }

        if (start < end) {  // If children exist then only.
            tNode& p = lazy[treeNode];
            for (int child : {2 * treeNode, 2 * treeNode + 1}) {
                tNode& c = lazy[child];
                if (p.type == 0) {
                    c.val = p.val;
                    c.type = 0;
                } else if (p.type == 1) {
                    if (c.type == 2) {
                        c.type = 1;
                    }
                    c.val += p.val;
                }
            }
        }
        lazy[treeNode].type = 2;
        lazy[treeNode].val = 0;  // reset the lazy tree for current node
    }

    // Completely oustide the range
    if (start > right || end < left) {
        tNode t;
        t.sqSum = 0;
        t.sum = 0;
        return t;
    }

    // Completely inside the range
    if (left <= start && end <= right) {
        return tree[treeNode];
    }

    // Partially inside and partially outside
    int mid = (start + end) / 2;
    int leftChild = 2 * treeNode, rightChild = 2 * treeNode + 1;
    tNode ans1 = lazyQuery(tree, lazy, start, mid, leftChild, left, right);
    tNode ans2 = lazyQuery(tree, lazy, mid + 1, end, rightChild, left, right);

    tNode ans;
    ans.sqSum = ans1.sqSum + ans2.sqSum;
    ans.sum = ans1.sum + ans2.sum;
    return ans;
}

void solve() {
    int n, q;

    cin >> n >> q;
    vt<int> arr(n);
    cin >> arr;

    vt<tNode> tree(3 * n);
    buildTree(arr, tree, 0, n - 1, 1);
    lNode l;  // Setting the lazy tree values to zero.
    l.type = 2;
    l.val = 0;
    vt<lNode> lazy(3 * n, l);

    while (q--) {
        int c, l, r, val;
        cin >> c >> l >> r;
        l--;
        r--;

        if (c == 2) {
            cout << lazyQuery(tree, lazy, 0, n - 1, 1, l, r).sqSum << "\n";
        }
        if (c == 1) {
            cin >> val;
            lazyUpdateTree(tree, lazy, 0, n - 1, 1, l, r, c, val);
        }
        if (c == 0) {
            cin >> val;
            lazyUpdateTree(tree, lazy, 0, n - 1, 1, l, r, c, val);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    FOR(tt, t) {
        cout << "Case " << tt << ":\n";
        solve();
    }
    return 0;
}