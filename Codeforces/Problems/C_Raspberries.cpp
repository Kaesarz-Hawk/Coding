// Author  : Kaesarz
// Date    : 09-10-2026
// Time    : 00:02

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int operations = INT_MAX;
    int evenCount = 0;

    for (int x : a)
    {
        operations = min(operations, (k - x % k) % k);
        if (x % 2 == 0)
            ++evenCount;
    }

    if (k == 4)
        operations = min(operations, max(0, 2 - evenCount));

    cout << operations << endl;
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