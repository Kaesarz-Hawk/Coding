// Author  : Kaesarz
// Date    : 23-07-2026
// Time    : 06:36

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

int bread_need = 0, sausage_need = 0, cheese_need = 0;

ll pieces_bread_have, pieces_sausage_have, pieces_cheese_have;
ll prices_bread, prices_sausage, prices_cheese;
ll money_have_rubles;

bool isValid(ll mid)
{

    ll required_bread = bread_need * mid;
    ll required_sausage = sausage_need * mid;
    ll required_cheese = cheese_need * mid;

    ll buy_bread = max(0LL, required_bread - pieces_bread_have);
    ll buy_sausage = max(0LL, required_sausage - pieces_sausage_have);
    ll buy_cheese = max(0LL, required_cheese - pieces_cheese_have);

    ll totalCost =
        buy_bread * prices_bread +
        buy_sausage * prices_sausage +
        buy_cheese * prices_cheese;

    if (totalCost <= money_have_rubles)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void binary_search()
{

    ll lo = 0, hi = 1e13, ans = -1;

    while (lo <= hi)
    {

        ll mid = lo + (hi - lo) / 2;

        if (isValid(mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << ans << endl;
}

void solve()
{

    string s;
    cin >> s;

    cin >> pieces_bread_have >> pieces_sausage_have >> pieces_cheese_have;
    cin >> prices_bread >> prices_sausage >> prices_cheese;
    cin >> money_have_rubles;

    // Counting
    for (char c : s)
    {
        if (c == 'B')
            bread_need++;
        else if (c == 'S')
            sausage_need++;
        else if (c == 'C')
            cheese_need++;
    }

    binary_search();
}

int main()
{

    SpeedxKH

    // int t;
    // cin >> t;
    // while (t--) solve();

    solve();

    return 0;
}