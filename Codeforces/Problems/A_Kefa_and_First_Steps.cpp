// Author  : Kaesarz
// Date    : 10-07-2026
// Time    : 23:11

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SpeedxKH                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int max_length = 1;
    int current_length = 1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] >= a[i - 1])
        {
            current_length++;
        }
        else
        {
            current_length = 1;
        }

        max_length = max(max_length, current_length);
        }
    cout << max_length << endl;
}

int main()
{
    SpeedxKH

    // int t;
    // cin >> t;
    // while (t--){ solve(); }

    // single test case
    solve();

    return 0;
}