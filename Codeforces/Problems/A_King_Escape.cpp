// Author  : Kaesarz
// Date    : 24-08-2026
// Time    : 19:49

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
#define SpeedxKH                 \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;
const double EPS = 1e-9;

// U R D L
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

// 8 Directions
const int dx8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void solve()
{

    int n;
    cin >> n;

    int qx, qy;
    int kx, ky;
    int tx, ty;

    cin >> qx >> qy;
    cin >> kx >> ky;
    cin >> tx >> ty;

    bool sameRowSide =
        (kx < qx && tx < qx) ||
        (kx > qx && tx > qx);

    bool sameColSide =
        (ky < qy && ty < qy) ||
        (ky > qy && ty > qy);

    if (sameRowSide && sameColSide)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    SpeedxKH

    solve();

    return 0;
}