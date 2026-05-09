#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        long long total_money_k;
        int people_n;
        cin >> people_n >> total_money_k;

        vector<long long> money(people_n);

        for (int i = 0; i < people_n; i++)
        {
            cin >> money[i];
        }

        for (int i = 0; i < people_n; i++)
        {
            if (total_money_k >= money[i])
            {
                cout << '1';
                total_money_k -= money[i];
            }
            else
            {
                cout << '0';
            }
        }

        cout << "\n";
    }

    return 0;
}