// Author  : Kaesarz
// Date    : 20-07-2026
// Time    : 22:37

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

    string s;
    cin >> s;

    map<ll, ll> precount;
    precount[0] = 1;
    ll pre = 0, ans = 0;

    for (const char c : s)
    {
        int x = (c - '0') - 1;
        pre += x;
        ans += precount[pre];
        precount[pre]++;
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