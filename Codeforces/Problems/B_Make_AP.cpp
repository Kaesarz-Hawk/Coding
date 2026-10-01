// Author  : Kaesarz
// Date    : 02-10-2026
// Time    : 00:50

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve()
{
    ll a, b, c;

    cin >> a >> b >> c;

    bool yes = false;
    if ((2 * b - c) % a == 0)
        if ((2 * b - c) / a > 0)
            yes = true;

    if ((a + c) % (2 * b) == 0)
        if ((a + c) / (2 * b) > 0)
            yes = true;

    if ((2 * b - a) % c == 0)
        if ((2 * b - a) / c > 0)
            yes = true;

    if (a - b == 0 && b - c == 0)
        yes = true;

    if (yes)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    SpeedxKH;

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}