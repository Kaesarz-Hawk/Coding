// Author  : Kaesarz
// Date    : 07-08-2026
// Time    : 15:59

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
    int n;
    if (cin >> n)
    {
        long long ans = 1;
        long long mod = 10000;

        for (int i = 1; i <= n; i++)
        {
            ans = (ans * i) % mod;
        }

        if (n >= 8)
        {
            cout << setfill('0') << setw(4) << ans << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
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