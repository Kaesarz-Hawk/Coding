// Author  : Kaesarz
// Date    : 05-10-2026
// Time    : 22:28

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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll max_beauty = 0;
    for (int i = 0; i < n; i++)
    {
        max_beauty += ceil((double)a[i] / x);
    }

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    ll min_beauty = ceil((double)sum / x);

    cout << min_beauty << " " << max_beauty << endl;
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