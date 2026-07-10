// Author  : Kaesarz
// Date    : 11-07-2026
// Time    : 02:23

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
    long long a_max_valueofbombtimer;
    long long b_bomb_intial_timer;
    int n_amounnt_of_tools;
    cin >> a_max_valueofbombtimer >> b_bomb_intial_timer >> n_amounnt_of_tools;

    int n = n_amounnt_of_tools;
    vector<int> tools(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tools[i];
    }

    long long total_time_c = b_bomb_intial_timer;
    for (int i = 0; i < n; i++)
    {
        total_time_c += min(1LL + tools[i], a_max_valueofbombtimer) - 1;
    }
    cout << total_time_c << "\n";
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