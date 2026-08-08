// Author  : Kaesarz
// Date    : 07-08-2026
// Time    : 16:06

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
    double h, m;
    cin >> h >> m;

    double hour = h * 30;
    double hourMove = m * 0.5;
    hour = hour + hourMove;

    double minute = m * 6;

    double ans = abs(hour - minute);

    if (ans > 180)
    {
        ans = 360 - ans;
    }

    cout << fixed << setprecision(7) << ans << endl;
}

int main()
{
    SpeedxKH

    // int t;
    // cin >> t;
    // while (t--){ solve(); }

    // single test case
    solve();

    return 0;
}