#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll n_positions, x1, x2, k_times;
        cin >> n_positions >> x1 >> x2 >> k_times;

        ll diff = abs(x2 - x1);
        ll shortestdistance = min(diff, n_positions - diff);

        ll time_need = 0;

        if (k_times == 0)
        {
            time_need = shortestdistance;
        }
        else
        {
            time_need = shortestdistance + k_times;
        }

        cout << time_need << endl;
    }

    return 0;
}