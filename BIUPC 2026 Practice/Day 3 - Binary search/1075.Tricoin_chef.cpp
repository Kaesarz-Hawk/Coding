// Author  : Kaesarz
// Date    : 31-07-2026
// Time    : 18:32

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
    long long n;
    cin >> n;

    long long lo = 0;
    long long hi = n;
    long long ans = 0;

    while (lo <= hi)
    {
        long long mid = lo + (hi - lo) / 2;

        long long need = mid * (mid + 1) / 2;

        if (need <= n)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << ans << endl;
}

int main()
{
    SpeedxKH

        int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    // single test case
    // solve();

    return 0;
}