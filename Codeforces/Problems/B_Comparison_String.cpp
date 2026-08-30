// Author  : Kaesarz
// Date    : 31-08-2026
// Time    : 01:26

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
    string s;
    cin >> n >> s;

    int maxLen = 1;
    int curLen = 1;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            curLen++;
        }
        else
        {
            maxLen = max(maxLen, curLen);
            curLen = 1;
        }
    }
    maxLen = max(maxLen, curLen);

    cout << maxLen + 1 << '\n';
}

int main()
{
    SpeedxKH;

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
} I have I think it's a good idea to have a Yeah.