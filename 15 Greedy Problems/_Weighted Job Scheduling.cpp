/*
Weighted Job Scheduling

You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset
overlap.

Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time,
finish time and the profit associated with the ith job.

Output
Output one integer, the maximum profit that can be achieved.

Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6

Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200

Sample Output
250
*/

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

bool compare(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
    return a.first.second < b.first.second;
}

int binarySearch(vt<pair<pair<int, int>, int>>& jobs, int index) {
    // Initialize 'lo' and 'hi' for Binary Search
    int lo = 0, hi = index - 1;

    // Perform binary Search iteratively
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (jobs[mid].first.second <= jobs[index].first.first) {
            if (jobs[mid + 1].first.second <= jobs[index].first.first)
                lo = mid + 1;
            else
                return mid;
        } else
            hi = mid - 1;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vt<pair<pair<int, int>, int>> jobs(n);
    For(i, n) cin >> jobs[i].first.first >> jobs[i].first.second >>
        jobs[i].second;

    sort(jobs.begin(), jobs.end(), compare);

    vt<int> dp(n);

    dp[0] = jobs[0].second;

    for (int i = 1; i < n; i++) {
        int option1 = dp[i - 1];
        int option2 = jobs[i].second;
        int index = binarySearch(jobs, i);
        if (index != -1) {
            option2 += dp[index];
        }

        dp[i] = max(option1, option2);
    }

    cout << dp[n - 1] << "\n";

    return 0;
}