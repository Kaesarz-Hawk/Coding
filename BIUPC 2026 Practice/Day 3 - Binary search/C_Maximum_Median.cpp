// Author  : Kaesarz
// Date    : 31-07-2026
// Time    : 12:14

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
    int n, k_operations;
    cin >> n >> k_operations;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    long long lo = a[n / 2];
    long long hi = a[n/2] + k_operations;
    long long ans = -1;
    while (lo <= hi)
    {
        long long mid = lo + (hi - lo) / 2;

        long long need = 0;

        for (int i = n / 2; i < n; i++)
        {
            if (a[i] < mid)
                need += mid - a[i];
        }

        if (need <= k_operations)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << ans << endl;
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