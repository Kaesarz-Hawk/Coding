// Author  : Kaesarz
// Date    : 14-07-2026
// Time    : 20:41

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
    int n;
    cin >> n;

    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll required_books = 1;

    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < required_books)
        {
            cout << "NO\n";
            return;
        }

        a[i + 1] += (a[i] - required_books);
        required_books++;
    }

    if (a[n - 1] >= required_books)

        cout << "YES\n";
    else
        cout << "NO\n";
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