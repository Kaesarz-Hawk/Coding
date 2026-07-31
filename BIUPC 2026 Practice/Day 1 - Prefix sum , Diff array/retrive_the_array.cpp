// Author  : Kaesarz
// Date    : 25-07-2026
// Time    : 12:51

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
    cin >> n;

    vector<ll> b(n);
    ll sum_b = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        sum_b += b[i];
    }

    
    ll sum_a = sum_b / (n + 1);

    
    for (int i = 0; i < n; i++)
    {
        cout << b[i] - sum_a << " ";
    }
    cout << endl;
}

int main()
{
    SpeedxKH

        int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}