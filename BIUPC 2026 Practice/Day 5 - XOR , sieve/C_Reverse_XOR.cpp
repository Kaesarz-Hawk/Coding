// Author  : Kaesarz
// Date    : 06-08-2026
// Time    : 19:05

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
    cin >> n;

    if (n == 0)
    {
        cout << "YES" << endl;
        return;
    }

    while ((n & 1) == 0)
    {
        n >>= 1;
    }

    string s = "";
    while (n > 0)
    {
        s += ((n & 1) ? '1' : '0');
        n >>= 1;
    }

    int len = s.length();

    bool is_palindrome = true;
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - 1 - i])
        {
            is_palindrome = false;
            break;
        }
    }

    if (!is_palindrome)
    {
        cout << "NO" << endl;
        return;
    }

    if (len % 2 == 1 && s[len / 2] == '1')
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
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