/* COCI '13 Contest 1 #4 Lopov */

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    vt<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second >> arr[i].first;
        // pairs are (value,weight)
    }

    multiset<int> bags;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        bags.insert(x);
    }

    // Sort on the basis of maximum value
    sort(arr.rbegin(), arr.rend());

    int i = 0;
    ll value = 0;
    while (i < n && !bags.empty()) {
        int curr_mass = arr[i].second;

        if (bags.lower_bound(curr_mass) != bags.end()) {
            value += arr[i].first;
            bags.erase(bags.lower_bound(curr_mass));
        }
        i++;
    }

    cout << value << "\n";
    return 0;
}