// Author  : Kaesarz
// Date    : 11-10-2026
// Time    : 23:40

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
    int n;
    long long k;
    cin >> n >> k;
    vector<pair<long long, int>> monsters(n);

    for (int i = 0; i < n; i++)
    {
        long long hp;
        cin >> hp;
        long long rem = hp % k;
        if (rem == 0)
            rem = k;               
        monsters[i] = {rem, i + 1}; 
    }

    
    sort(monsters.begin(), monsters.end(), [](const pair<long long, int> &a, const pair<long long, int> &b)
         {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second; });

    for (int i = 0; i < n; i++)
    {
        cout << monsters[i].second << (i == n - 1 ? "" : " ");
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
        cout << endl;
    }

    return 0;
}