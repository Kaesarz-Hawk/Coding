// Author  : Kaesarz
// Date    : 25-07-2026

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Read all operations
    vector<int> l(m), r(m), d(m);
    for (int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i] >> d[i];
    }

    // Count how many times each operation is used
    vector<ll> op_count(m + 1, 0);
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;

        op_count[x - 1]++;
        op_count[y]--;
    }

    // Prefix Sum -> operation count
    for (int i = 1; i < m; i++)
    {
        op_count[i] += op_count[i - 1];
    }

    // Difference Array on original array
    vector<ll> diff(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        ll new_d = 1LL * d[i] * op_count[i];

        diff[l[i] - 1] += new_d;
        diff[r[i]] -= new_d;
    }

    // Reconstruct
    ll cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += diff[i];
        a[i] += cur;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    SpeedxKH
    solve();
    return 0;
}