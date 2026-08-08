// Author  : Kaesarz
// Date    : 07-08-2026
// Time    : 15:57

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
    long long a, b;
    cin >> a >> b;
    if (a % b == 0 || b % a == 0)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
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