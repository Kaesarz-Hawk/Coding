// Author  : Kaesarz
// Date    : 20-10-2026
// Time    : 21:23

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
    long long k, b, s;
    cin >> n >> k >> b >> s;

    long long min_sum = k * b;
    long long max_sum = k * b + n * (k - 1);

    if (s < min_sum || s > max_sum)
    {
        cout << -1 << endl;
        return;
    }

    vector<long long> a(n, 0);
    a[0] = min_sum;
    ll remaining = s - min_sum;

    for (int i = 0; i < n; i++)
    {
        ll add = min(remaining, k - 1);
        a[i] += add;
        remaining -= add;
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    SpeedxKH;

    int t;
     cin >> t;
     while (t--) solve();

    
    return 0;
}