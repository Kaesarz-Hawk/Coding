// Author  : Kaesarz
// Date    : 23-07-2026
// Time    : 12:44

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
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        int digit = s[i] - '0';
        int inverted = 9 - digit;

        if (i == 0 && digit == 9)
            continue;

        if (inverted < digit)
        {
            s[i] = inverted + '0';
        }
    }

    cout << s << endl;
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