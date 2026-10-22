// Author  : Kaesarz
// Date    : 22-10-2026
// Time    : 20:58

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int whiteCount = 0;
    int ans = INT_MAX;

    for (int i = 0; i < k; i++)
    {
        if (s[i] == 'W')
            whiteCount++;
    }

    ans = whiteCount;

    for (int i = k; i < n; i++)
    {
        if (s[i - k] == 'W')
            whiteCount--;

        if (s[i] == 'W')
            whiteCount++;

        ans = min(ans, whiteCount);
    }

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