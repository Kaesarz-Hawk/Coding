// Author  : Kaesarz
// Date    : 30-06-2026
// Time    : 20:50

#include <bits/stdc++.h>
using namespace std;

#define ll long long
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

    string s;
    cin >> s;

    bool has01 = false, has10 = false;

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '0' && s[i + 1] == '1')
            has01 = true;
        if (s[i] == '1' && s[i + 1] == '0')
            has10 = true;
    }

    if (has01 && has10)
        cout << 1 << "\n";

    else if (has01 || has10)
        cout << 2 << "\n";
    else
        cout << 1 << "\n";
}

int main()
{
    SpeedxKH

        int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}