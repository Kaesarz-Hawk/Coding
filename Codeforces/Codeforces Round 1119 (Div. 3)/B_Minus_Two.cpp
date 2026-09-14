// Author  : Kaesarz
// Date    : 05-09-2026
// Time    : 20:51

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

    int count_odd = 0, count_even0 = 0, count_even2 = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x % 2 == 1)
        {
            count_odd++;
        }
        else
        {
            if (x % 4 == 0)
                count_even0++;
            else
                count_even2 ++; 
        }
    }

    int ans = max({count_odd, count_even0, count_even2});

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