// Author  : Kaesarz
// Date    : 20-10-2026
// Time    : 20:27

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
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.rbegin(), a.rend());

    int l = 0, r = n - 1;
    int count = 0;

    while (l <= r)
    {
        ll higehst = a[l];
        while (l < r && higehst <= d)
        {
            higehst += a[l];
            r--;
        }
        if (higehst > d)
        {
            count++;
            l++;
        }
        else
        {
            break;
        }
    }

    cout << count << endl;
}

int main()
{
    SpeedxKH;

    // single test case
    solve();

    return 0;
}