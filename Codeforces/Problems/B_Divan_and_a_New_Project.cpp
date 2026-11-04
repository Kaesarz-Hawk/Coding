// Author  : Kaesarz
// Date    : 04-11-2026
// Time    : 01:39

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

    vector<pair<int, int>> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i; 
    }

    sort(arr.begin() + 1, arr.end(), greater<pair<int, int>>());

    vector<int> x(n + 1);
    const int x0 = 0;
    x[0] = 0;

    for (int i = 1; i <= n; i++)
    {

        if (i % 2 == 1)
            x[arr[i].second] = (i + 1) / 2;
        else
            x[arr[i].second] = -(i / 2);
    }

    ll total_time = 0;
    for (int i = 1; i < x.size(); i++)
    {

        total_time += 2LL * abs(x[0] - x[arr[i].second]) * arr[i].first;
    }

    cout << total_time << endl;

    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
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