// Author  : Kaesarz
// Date    : 31-08-2026
// Time    : 01:47

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
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int diff = abs(p[i] - (i + 1));
        ans = __gcd(ans, diff);
    }

    cout << ans << endl;
}

int main()
{
    SpeedxKH

        int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}