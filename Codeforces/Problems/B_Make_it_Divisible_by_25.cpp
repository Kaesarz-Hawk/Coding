// Author  : Kaesarz
// Date    : 02-10-2026
// Time    : 17:10

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

int ops(string s, string digit)
{
    int n = s.size();
    int m = digit.size();
    int i = n - 1, j = m - 1;
    int count = 0;

    while (i >= 0 && j >= 0)
    {
        if (s[i] == digit[j])
        {
            j--;
        }
        else
        {
            count++;
        }
        i--;
    }

    if (j >= 0)
    {
        return INT_MAX; 
    }

    return count; 
}

void solve()
{
    ll n;
    cin >> n;

    string s = to_string(n);

    if (n % 25 == 0)
    {
        cout << 0 << endl;
        return;
    }

    vector<string> digits = {"00", "25", "50", "75"};
    int ans = INT_MAX;
    for (auto digit : digits)
    {
        int mini = ops(s, digit);
        ans = min(ans, mini); 
    }

    cout << ans << endl;
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