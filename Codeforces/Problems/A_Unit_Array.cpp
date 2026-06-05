#include <bits/stdc++.h>
using namespace std;
#define ll      long long
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;
    int multipication = 1;
    bool goodmulti = false;
    bool goodsum = false;

    int operations = 0;

    for (int j = 0; j < n; j++)
    {
        sum += arr[j];
        multipication *= arr[j];
    }
    goodsum = (sum >= 0);
    goodmulti = (multipication == 1);

    if (!goodmulti || !goodsum)
    {
        while (!goodmulti || !goodsum)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == -1)
                {
                    arr[i] = 1;
                    operations++;

                    sum = 0;
                    multipication = 1;

                    for (int j = 0; j < n; j++)
                    {
                        sum += arr[j];
                        multipication *= arr[j];
                    }

                    goodsum = (sum >= 0);             
                    goodmulti = (multipication == 1); 

                    if (goodmulti && goodsum)
                        break;
                    break;
                }
            }
        }
    }
    else
    {
        operations = 0;
    }

    cout << operations << endl;
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