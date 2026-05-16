#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define InTheNameOfAllah         \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
int main()
{
    InTheNameOfAllah;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        ll zero = 0;
        ll one = 0;
        ll two = 0;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if (x == 0)
            {
                zero++;
            }
            else if (x == 1)
            {
                one++;
            }
            else
            {
                two++;
            }
        }

        ll joraacount = min(one, two);

        one -= joraacount;
        two -= joraacount;
        ll ans = 0;
        ans += zero;
        ans += joraacount;
        ans += one / 3;
        ans += two / 3;

        cout << ans << endl;
    }

    return 0;
}