// Author  : Kaesarz
// Date    : 04-06-2026
// Time    : 18:40

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SpeedxKH ios_base::sync_with_stdio(false);  cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve()
{
    int n_lengthofstring;
    cin >> n_lengthofstring;

    int k_characterstodelete;
    cin >> k_characterstodelete;

    string s;
    cin >> s;

    map<char, int> freq;

    for (char c : s)
    {
        freq[c]++;
    }

    int odd_count = 0;

    for (auto it : freq)
    {
        if (it.second % 2 == 1)
        {
            odd_count++;
        }
    }

   
    if (odd_count - k_characterstodelete <= 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    SpeedxKH

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}