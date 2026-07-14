// Author  : Kaesarz
// Date    : 14-07-2026
// Time    : 20:56

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SpeedxKH                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve()
{
    int n_meausrement, m_motivationalposts;
    cin >> n_meausrement >> m_motivationalposts;

    vector<ll> a(n_meausrement + 1);
    for (int i = 1; i <= n_meausrement; i++)
        cin >> a[i];

    vector<char> isBreak(n_meausrement + 1, 0);
    for (int i = 0; i < m_motivationalposts; i++)
    {
        int b;
        cin >> b;
        isBreak[b] = 1;
    }

    ll dpPlus = 0, dpMinus = -LLINF;

    for (int i = n_meausrement; i >= 1; i--)
    {
        ll newPlus, newMinus;
        if (isBreak[i])
        {
            ll best = max(dpPlus, dpMinus);
            newPlus = best + a[i];
            newMinus = best - a[i];
        }
        else
        {
            newPlus = dpPlus + a[i];
            newMinus = dpMinus - a[i];
        }
        dpPlus = newPlus;
        dpMinus = newMinus;
    }

    cout << max(dpPlus, dpMinus) << "\n";
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

    return 0;
}