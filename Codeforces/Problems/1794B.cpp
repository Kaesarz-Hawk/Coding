#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SpeedxKH                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    SpeedxKH;

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

                    if (a[i] == 1)
            {
                a[i]++;
            }
        }

        int operations = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (a[i + 1] % a[i] == 0)
            {
                a[i + 1]++;
                operations++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << '\n';
    }

    return 0;
}