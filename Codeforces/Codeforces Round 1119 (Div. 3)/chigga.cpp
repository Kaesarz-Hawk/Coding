#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> freq(n + 2, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] <= n + 1)
            freq[arr[i]]++;
    }
    int zeroCnt = freq[0];
    if (zeroCnt == 0)
    {
        cout << "YES\n";
        cout << string(n, 'A') << '\n';
        return;
    }
    if (zeroCnt == 1)
    {
        cout << "NO\n";
        return;
    }
    int mexLimit = 0;
    while (mexLimit <= n && freq[mexLimit] >= 2)
        mexLimit++;
    string ans(n, 'C');
    vector<bool> gotA(mexLimit, false), gotB(mexLimit, false);
    for (int i = 0; i < n; i++)
    {
        int val = arr[i];
        if (val < mexLimit)
        {
            if (!gotA[val])
            {
                ans[i] = 'A';
                gotA[val] = true;
            }
            else if (!gotB[val])
            {
                ans[i] = 'B';
                gotB[val] = true;
            }
            else
            {
                ans[i] = 'A';
            }
        }
        else
        {
            ans[i] = 'C';
        }
    }
    cout << "YES\n"
         << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}