// Author  : Kaesarz
// Date    : 05-09-2026
// Time    : 20:45

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
    int n, k;
    string s;
    cin >> n >> k >> s;

    int ans = 0;

    for (int i = 0; i < n; i += k)
    {
        bool hasZero = false;
        
        for (int j = i; j < i + k; j++)
        {
            if (s[j] == '0')
            {
                hasZero = true;
                break;
            }
        }
        if (!hasZero)
            ans++;
    }
    cout << ans << '\n';
}

int main()
{
    SpeedxKH;

     int t;
     cin >> t;
     while (t--) solve();

    // single test case
   // solve();

    return 0;
}