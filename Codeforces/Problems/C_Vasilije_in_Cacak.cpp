// Author  : Kaesarz
// Date    : 02-07-2026
// Time    : 20:30
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SpeedxKH                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;
void solve()
{
    ll n_maximum, k_distincts, x_target;
    cin >> n_maximum >> k_distincts >> x_target;

    // Minimum Sum
    // S = n/2(a + l)
    // n = k_distincts, a = 1, l = k_distincts
    ll min_sum = (k_distincts * (1 + k_distincts)) / 2;

    // Maximum Sum
    // S = n/2(a + l)
    // n = k_distincts, a = n_maximum - k_distincts + 1, l = n_maximum
    ll max_sum = (k_distincts * ((n_maximum - k_distincts + 1) + n_maximum)) / 2;

    if (x_target >= min_sum && x_target <= max_sum)
    {
        cout << "YES" << "\n";
    }
    else
    {
        cout << "NO" << "\n";
    }
}
int main()
{
    SpeedxKH int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}