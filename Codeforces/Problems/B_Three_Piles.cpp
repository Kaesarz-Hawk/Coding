// Author  : Kaesarz
// Date    : 25-09-2026
// Time    : 19:28

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

    ll ans = max(abs(a - b), abs(a + c - b));
    cout << ans << endl;
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