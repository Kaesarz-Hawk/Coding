#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
        }

        long long operations = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            while (a[i] >= a[i + 1] && a[i] > 0)
            {
                a[i] /= 2;
                operations++;
            }

            if (a[i] >= a[i + 1])
            {
                operations = -1;
                break;
            }
        }

        cout << operations << endl;
    }

    return 0;
}