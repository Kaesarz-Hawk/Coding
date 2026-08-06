// Author  : Kaesarz
// Date    : 01-08-2026
// Time    : 21:41

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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++)
    {
        int count = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        cout << count << " ";
    }
    cout << endl;
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