// Author  : Kaesarz
// Date    : 29-09-2026
// Time    : 21:39

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int blocks = 0;
    for (int i = 0; i < n; i++)
    {
        
        if (a[i] != 0 && (i == 0 || a[i - 1] == 0))
        {
            blocks++;
        }
    }

    
    if (blocks == 0)
    {
        cout << 0 << endl;
    }
    else if (blocks == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 2 << endl;
    }
}

int main()
{
    SpeedxKH;

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}