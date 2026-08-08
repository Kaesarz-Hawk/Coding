// Author  : Kaesarz
// Date    : 07-08-2026
// Time    : 15:33

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
    string date;
    getline(cin, date);

    if (date == "1 Shawwal")
    {
        cout << "Eid-ul-Fitr";
    }
    else if (date == "10 Zil Hajj")
    {
        cout << "Eid-ul-Adha";
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