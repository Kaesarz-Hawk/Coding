// Author  : Kaesarz
// Date    : 15-09-2026
// Time    : 17:52

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
    int x_endpoint, k_constraint_jump;
    cin >> x_endpoint >> k_constraint_jump;

    if (x_endpoint % k_constraint_jump != 0)
    {
        cout << 1 << endl;
        cout << x_endpoint << endl;
    }
    else
    {

        cout << 2 << endl;
        cout << 1 << ' ' << x_endpoint - 1 << endl;
    }
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