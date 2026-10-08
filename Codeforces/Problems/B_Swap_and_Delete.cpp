// Author  : Kaesarz
// Date    : 08-10-2026
// Time    : 23:34

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

    int one = 0, zero = 0;
    for (char c : s)
    {
        if (c == '0')
            zero++;
        else
            one++;
    }

    int swap_cost = 1;
    int const delete_cost = 0;

    for (char c : s)
    {
        if (c == '0')
        {
            if (one > 0)
            {
                one--;
                swap_cost += 1;
              
            }
            else
            {
                break;
            }
        }
        else
        {
            if (zero > 0)
            {
                zero--;
                swap_cost += 1;
            }
            else
            {
                break;
            }
        }
    }

    cout << (int)s.size() - swap_cost << endl;
}

int main()
{
    SpeedxKH;

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}