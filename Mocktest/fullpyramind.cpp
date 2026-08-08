// Author  : Kaesarz
// Date    : 07-08-2026
// Time    : 15:58

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
    if (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {

            for (int j = 0; j < n - i; j++)
            {
                cout << " ";
            }

            for (int j = 0; j < i; j++)
            {
                cout << "*";
                if (j < i - 1)
                {
                    cout << " ";
                }
            }
            cout << "\n";
        }
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