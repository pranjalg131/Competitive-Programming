/*
Paint Houses

You want to paint your house. The total area of your house is D units. There are
a total of N workers. The ith worker is available after time Ti, has hiring cost
Xi and speed Yi. This means he becomes available for hiring from time Ti and
remains available after that. Once available, you can hire him with cost Xi,
after which he will start painting the house immediately, covering exactly Yi
units of house with paint per time unit. You may or may not hire a worker and
can also hire or fire him at any later point of time. However, no more than 1
worker can be painting the house at a given time. Since you want the work to be
done as fast as possible, figure out a way to hire the workers, such that your
house gets painted at the earliest possible time, with minimum cost to spend for
hiring workers. Note: You can hire a previously hired worker without paying him
again.

Input
The first line of input contains two integers "N D", the number of workers and
the area of your house respectively. The ith of the next N lines denotes the ith
worker, and contains three integers "Ti Xi Yi", described in the statement.

Output
Output one integer, the minimum cost that you can spend in order to get your
house painted at the earliest.

Constraints
1 ≤ N, T, X, Y ≤ 10^5
1 ≤ D ≤ 10^11

Sample Input
3 3
1 1 1
2 2 2
3 1 5

Sample Output
3
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

void solve() {
    int n, d;
    cin >> n >> d;
    vt<array<int, 3>> a(n);
    cin >> a;
    sort(all(a));
    a.pb({(int)1e12, 0, 0});
    int ans = 0, mx_speed = 0, painted = 0, j = 0;

    for (int i = 0; i < n && painted < d; i = j) {
        j = i;
        int cost = 0;
        // the inner loop skips people with same time and selects best among
        // them
        while (j < n && a[j][0] == a[i][0]) {
            if (a[j][2] > mx_speed) {
                mx_speed = a[j][2];
                cost = a[j][1];
            } else if (a[j][2] == mx_speed) {
                amin(cost, a[j][1]);
            }
            j++;
        }
        ans += cost;
        painted += (a[j][0] - a[i][0]) * mx_speed;
    }
    assert(painted >= d);
    cout << ans;
}

signed main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    FOR(tt, t) solve();
    return 0;
}