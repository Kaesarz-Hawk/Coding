// Author  : Kaesarz
// Date    : 18-10-2026
// Time    : 20:11

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

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    map<int, int> max_a, max_b;

    // A 
    int l = 0;
    while (l < n) {
        int r = l;
        while (r < n && a[r] == a[l]) {
            r++;
        }
        max_a[a[l]] = max(max_a[a[l]], r - l);
        l = r;
    }

    // B 
    l = 0;
    while (l < n) {
        int r = l;
        while (r < n && b[r] == b[l]) {
            r++;
        }
        max_b[b[l]] = max(max_b[b[l]], r - l);
        l = r;
    }

    int ans = 0;
    for (auto &[val, count] : max_a) {
        ans = max(ans, count + max_b[val]);
    }
    for (auto &[val, count] : max_b) {
        ans = max(ans, count + max_a[val]);
    }

    cout << ans << endl;
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