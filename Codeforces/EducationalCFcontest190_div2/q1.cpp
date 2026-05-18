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
        ll a;
        ll b;
        ll c;

        cin >> c >> a >> b;

        ll cost = 0;

        ll fullGroups = c / 3;
        ll remainder = c % 3;

        cost += fullGroups * min(b, 3 * a);

        if (remainder > 0)
        {
            cost += min(b, remainder * a);
        }

        cout << cost << endl;
    }
    return 0;
}