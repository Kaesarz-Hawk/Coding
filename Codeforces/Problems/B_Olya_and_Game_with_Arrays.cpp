// Author  : Kaesarz
// Date    : 10-10-2026
// Time    : 22:30

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

    ll min_of_first = LLINF;
    vector<ll> second_minimum;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<ll> arr(m);
        for (int j = 0; j < m; j++)
        {
            cin >> arr[j];
        }

        sort(arr.begin(), arr.end());
        min_of_first = min(min_of_first, arr[0]);
        second_minimum.push_back(arr[1]);
    }
    ll sum_second = accumulate(second_minimum.begin(), second_minimum.end(), 0LL);
    ll min_second = *min_element(second_minimum.begin(), second_minimum.end());

    ll result = sum_second - min_second + min_of_first;
    cout << result << endl;
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