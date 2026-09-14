// Author  : Kaesarz
// Date    : 05-09-2026
// Time    : 21:06

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
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n + 2, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] <= n + 1)
            cnt[a[i]]++;
    }

    if (cnt[0] == 0)
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            cout << 'A';
        cout << '\n';
        return;
    }

    if (cnt[0] == 1)
    {
        cout << "NO\n";
        return;
    }

    int m = 0;
    while (m <= n && cnt[m] >= 2)
        m++;

    string s(n, 'C');
    vector<int> first(m, 0), second(m, 0);

    for (int i = 0; i < n; i++)
    {
        int x = a[i];

        if (x < m)
        {
            if (first[x] == 0)
            {
                s[i] = 'A';
                first[x] = 1;
            }
            else if (second[x] == 0)
            {
                s[i] = 'B';
                second[x] = 1;
            }
            else
            {
                s[i] = 'A';
            }
        }
        else
        {
            s[i] = 'C';
        }
    }

    cout << "YES\n"
         << s << '\n';
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