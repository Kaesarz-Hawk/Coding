// Author  : Kaesarz
// Date    : 15-09-2026
// Time    : 18:28

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
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + a[i];

    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;

        long long totalSum = pre[n];
        long long rangeSum = pre[r] - pre[l - 1];

        long long count = r - l + 1;
        long long newRangeSum = count * k;
        long long newSum = totalSum - rangeSum + newRangeSum;
        
        if (newSum % 2 != 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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