#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int current = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (a[i] == current)
        {
            current++;
        }
    }

    int remaining = n - (current - 1);

    int ans = (remaining + k - 1) / k;
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}