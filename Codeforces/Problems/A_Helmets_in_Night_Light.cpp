// Author  : Kaesarz
// Date    : 10-10-2026
// Time    : 04:32

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
    ll p;
    cin >> n >> p;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];


    vector<pair<ll, ll>> residents(n);
    for (int i = 0; i < n; i++)
    {
        residents[i] = {b[i], a[i]}; 
    }

    sort(residents.begin(), residents.end());

    ll total_cost = p; 
    ll remaining = n - 1;

    for (int i = 0; i < n && remaining > 0; i++)
    {
        ll cost = residents[i].first;
        ll limit = residents[i].second;

        if (cost >= p)
            break; 

        ll take = min(remaining, limit);
        total_cost += take * cost;
        remaining -= take;
    }

    total_cost += remaining * p; 
    cout << total_cost << endl;
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