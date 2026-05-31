#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;

        if (x <= 20)
        {
            cout << x * 10 << endl;
        }
        else
        {
            int first_phase_cost = 20 * 10; 
            int remaining = x - 20;
            int balls_lagbo = (remaining + 1) / 2; 
            int second_phase_cost = balls_lagbo * 5;

            cout << first_phase_cost + second_phase_cost << endl;
        }
    }

    return 0;
}