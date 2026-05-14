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
        int n, m;
        cin >> n >> m;

        bool found = false;

        for (int start = 1; start < m; start++)
        {
            vector<int> a(n + 2);
            a[0] = 0;
            a[1] = start;

            for (int i = 1; i <= n; i++)
            {
                a[i + 1] = ((a[i] - a[i - 1]) % m + m) % m;
            }

            bool valid = (a[n + 1] == 0);
            for (int i = 1; i <= n; i++)
            {
                if (a[i] == 0)
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {
                for (int i = 1; i <= n; i++)
                    cout << a[i] << " ";
                cout << "\n";
                found = true;
                break;
            }
        }

        if (!found)
            cout << -1 << "\n";
    }

    return 0;
}