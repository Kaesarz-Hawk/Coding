// Author  : Kaesarz
// Date    : 12-10-2026
// Time    : 23:50

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
    int n, k;
    long long q;
    cin >> n >> k >> q;

    long long total_ways = 0;
    long long len = 0;

    for (int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        if (temp <= q)
        {
            len++;
        }
        else
        {
            if (len >= k)
            {
                long long m = len - k + 1;
                total_ways += m * (m + 1) / 2;
            }
            len = 0;
        }
    }
    if (len >= k)
    {
        long long m = len - k + 1;
        total_ways += m * (m + 1) / 2;
    }

    cout << total_ways << endl;
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