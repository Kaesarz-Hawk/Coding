// Author  : Kaesarz
// Date    : 07-08-2026
// Time    : 15:41

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
    string s;
    if (cin >> s)
    {
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            cout << s[i];
            if ((n - 1 - i) % 3 == 0 && i != n - 1)
            {
                cout << ",";
            }
        }
        cout << "\n";
    }
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