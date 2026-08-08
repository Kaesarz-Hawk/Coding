// Author  : Kaesarz
// Date    : 07-08-2026
// Time    : 16:33

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
    int a, b;
    cin >> a >> b;

    int carry = 0;

    while (a > 0 or b > 0)
    {
        int digit1 = a % 10;
        int digit2 = b % 10;

        if (digit1 + digit2 + carry >= 10)
        {
            cout << "Yes" << endl;
            return;
        }

        carry = 0;

        a /= 10;
        b /= 10;
    }

    cout << "No" << endl;
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