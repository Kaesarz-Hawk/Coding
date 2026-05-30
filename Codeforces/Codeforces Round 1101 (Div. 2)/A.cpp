#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SpeedxKH  ios_base::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);
int main()
{
    SpeedxKH;
 
    int t;
    cin >> t;
 
    while (t--)
    {
        int n_freinds;
        cin >> n_freinds;
        vector<int> a(n_freinds);
        for (int i = 0; i < n_freinds; i++)
        {
            cin >> a[i];
        }
 
        int ans = n_freinds;
 
        for (int i = 0; i < n_freinds; i++)
        {
            int l = 0, r = 0;
            for (int j = 0; j < n_freinds; j++)
            {
                if (a[j] < a[i])
                    l++;
 
                else if (a[j] > a[i])
                    r++;
            }
            ans = min(ans, max(l, r));
        }
 
        cout << ans << "\n";
    }
    return 0;
}