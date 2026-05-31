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
        int N_particpants, X_selectable, K_topeligible;
        cin >> N_particpants >> X_selectable >> K_topeligible;

        vector<int> scores(N_particpants);
        for (int i = 0; i < N_particpants; i++)
        {
            cin >> scores[i];
        }

        sort(scores.begin(), scores.end(), greater<int>());

        int eligible = 0;
        int clusters = 0;

        for (int i = 0; i < N_particpants; i++)
        {

            if (i == 0 or scores[i] != scores[i - 1])
            {
                if (clusters == K_topeligible)
                    break;
                clusters++;
            }
            eligible++;
        }

        cout << min(eligible, X_selectable) << endl;
    }

    return 0;
}