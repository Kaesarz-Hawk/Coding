// Author  : Kaesarz
// Date    : 04-08-2026
// Time    : 11:49

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
    long long n, m;
    cin >> n >> m;

    if (n >= 31)
    {
        cout << m << endl;
    }
    else
    {
        cout << m % (1LL << n) << endl;
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