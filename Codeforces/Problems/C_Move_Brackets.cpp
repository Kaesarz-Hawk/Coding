// Author  : Kaesarz
// Date    : 07-11-2026
// Time    : 23:13

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(nullptr);

// Bitwise Shortcuts
#define popcount(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x)
#define msb(x) __lg(x)

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;
const double EPS = 1e-9;

// Grid Directions (U, R, D, L & 8-Dir)
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// --- Utility Functions ---
ll getXOR(ll n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

ll ceil_div(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b != 0); }
ll lcm(ll a, ll b) { return (a / __gcd(a, b)) * b; }

ll binpow(ll a, ll b, ll m = MOD) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void YES() { cout << "YES" << endl; }
void NO() { cout << "NO" << endl; }

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int moves = 0;
    int leftbracket_needed = 0;
    int rightbracket_needed = 0;

    
    for(int i = 0; i < (int)s.size() - 1; i++) {
        if(s[i] == '(' and s[i+1] == ')') {
            s.erase(i, 2);
            i = -1;        
        }
    }

    moves = sz(s) / 2;
    cout << moves << endl;
}

int main() {
    SpeedxKH;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}