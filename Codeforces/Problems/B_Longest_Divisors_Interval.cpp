// Author  : Kaesarz
// Date    : 11-07-2026
// Time    : 02:50

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SpeedxKH                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void solve()
{
    ll n;
    cin >> n;

    ll array[2] = {1, 1};
    ll i = 1;

    while (n % i == 0)
    {
        array[1] = i;
        i++;
    }

    ll l = array[0];
    ll r = array[1];

    ll output = r - l + 1;
    cout << output << "\n";
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