// Author  : Kaesarz
// Date    : 24-07-2026
// Time    : 04:24

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
    int n_ribbonLength;
    cin >> n_ribbonLength;

    int a_cutLength, b_cutLength, c_cutLength;
    cin >> a_cutLength >> b_cutLength >> c_cutLength;

    vector<int> dp(n_ribbonLength + 1, -INF);

    dp[0] = 0;

    for (int i = 1; i <= n_ribbonLength; i++)
    {

        if (i >= a_cutLength)
            dp[i] = max(dp[i], dp[i - a_cutLength] + 1);

        if (i >= b_cutLength)
            dp[i] = max(dp[i], dp[i - b_cutLength] + 1);

        if (i >= c_cutLength)
            dp[i] = max(dp[i], dp[i - c_cutLength] + 1);
    }

    cout << dp[n_ribbonLength] << endl;
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