// Author  : Kaesarz
// Date    : 30-06-2026
// Time    : 20:40

#include <bits/stdc++.h>
using namespace std;
#define SpeedxKH                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve()
{
    ll x;
    cin >> x;

    int len = to_string(x).size();

    ll p = 1;
    while (len--)
    {
        p *= 10;
    }

    cout << p + 1 << '\n';
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