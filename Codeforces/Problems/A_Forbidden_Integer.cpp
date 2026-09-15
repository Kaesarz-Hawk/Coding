// Author  : Kaesarz
// Date    : 14-09-2026
// Time    : 20:23

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve()
{
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> ans;

    if (x != 1)
    {
        
        for (int i = 0; i < n; i++)
            ans.push_back(1);
    }
    else
    {
        
        if (k == 1)
        {
            
            cout << "NO" << endl;
            return;
        }
        else if (k == 2)
        {
            
            if (n % 2 == 0)
            {
                for (int i = 0; i < n / 2; i++)
                    ans.push_back(2);
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            
            if (n % 2 == 0)
            {
                for (int i = 0; i < n / 2; i++)
                    ans.push_back(2);
            }
            else
            {
                ans.push_back(3);
                int rem = n - 3;
                for (int i = 0; i < rem / 2; i++)
                    ans.push_back(2);
            }
        }
    }

    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (int v : ans)
        cout << v << " ";
    cout << endl;
}
int main()
{
    SpeedxKH;

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}