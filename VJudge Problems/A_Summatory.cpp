#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

                long long ans = 0;
        for (long long i = 1; i <= n; i++)
        {
            ans += (i * (i + 1) / 2) * (i * (i + 1) / 2);
        }
        cout << ans << endl;
    }
}