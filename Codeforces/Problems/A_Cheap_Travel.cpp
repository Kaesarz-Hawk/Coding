// Author  : Kaesarz
// Date    : 24-07-2026
// Time    : 04:01

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
    int n_rides_needed;
    int m_times_rides_possible;
    int a_1ride_cost;
    int b_mride_cost;

    cin >> n_rides_needed >> m_times_rides_possible >> a_1ride_cost >> b_mride_cost;

    int only_single = n_rides_needed * a_1ride_cost;

    int full_special = (n_rides_needed / m_times_rides_possible) * b_mride_cost;
    int remaining_single = (n_rides_needed % m_times_rides_possible) * a_1ride_cost;
    int special_then_single = full_special + remaining_single;

    int all_special = ((n_rides_needed + m_times_rides_possible - 1) / m_times_rides_possible) * b_mride_cost;

    cout << min({only_single, special_then_single, all_special}) << endl;
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