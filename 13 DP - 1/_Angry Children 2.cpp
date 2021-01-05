/*Angry Children
Send Feedback
Bill Gates is on one of his philanthropic journeys to a village in Utopia. He
has N packets of candies and would like to distribute one packet to each of the
K children in the village (each packet may contain different number of candies).
To avoid a fight between the children, he would like to pick K out of N packets
such that the unfairness is minimized. Suppose the K packets have (x1, x2,
x3,....xk) candies in them, where xi denotes the number of candies in the ith
packet, then we define unfairness as unfairness=0; for(i=0;i<n;i++)
for(j=0;j<n;j++)
    unfairness+=abs(xi-xj)
abs(x) denotes absolute value of x.

Input Format
The first line contains an integer N.
The second line contains an integer K.
N lines follow each integer containing the candy in the ith packet.

Output Format
A single integer which will be minimum unfairness.

Constraints
2<=N<=10^5
2<=K<=N
0<= number of candies in each packet <=10^9

Sample Input
7
3
10
100
300
200
1000
20
30

Sample Output
40
Explanation
Bill Gates will choose packets having 10, 20 and 30 candies.So unfairness will
be |10-20| + |20-30| + |10-30| = 40. We can verify that it will be minimum in
this way.*/

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
    ll n, k;
    cin >> n >> k;
    vt<ll> arr(n);
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }

    sort(all(arr));

    vt<ll> sum(n);
    sum[0] = arr[0];
    for (int i = 1; i < sum.size(); i++) {
        sum[i] = sum[i - 1] + arr[i];
    }

    ll curr = 0;
    for (int i = 1; i < k; i++) {
        curr += i * arr[i] - sum[i - 1];
    }

    ll res = curr;

    if (k > 1) {
        for (int i = k; i < arr.size(); i++) {
            curr += (k - 1) * arr[i] - (sum[i - 1] - sum[i - k]);
            curr -= -(k - 1) * arr[i - k] + (sum[i - 1] - sum[i - k]);
            res = min(res, curr);
        }
    }

    cout << res << "\n";

    return 0;
}