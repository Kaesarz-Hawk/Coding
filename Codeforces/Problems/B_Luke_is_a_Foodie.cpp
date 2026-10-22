// Author  : Kaesarz
// Date    : 22-10-2026
// Time    : 05:31

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
    int n, x;
    cin >> n >> x;

    int changes = 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int l = a[0] - x;
    int r = a[0] + x;

    for (int i = 1; i < n; i++)
    {
        int current_l = a[i] - x;
        int current_r = a[i] + x;
        l = max(l, current_l);
        r = min(r, current_r);

        if (l > r)
        {
            changes++;
            l = current_l;
            r = current_r;
        }
    }
    cout << changes << endl;
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