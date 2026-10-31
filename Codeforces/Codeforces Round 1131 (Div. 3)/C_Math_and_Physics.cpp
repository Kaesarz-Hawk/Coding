// Author  : Kaesarz
// Date    : 31-10-2026
// Time    : 21:05

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    bool any_ge2 = false;
    bool internal_ge2 = false;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if (a[i] >= 2) {
            any_ge2 = true;
            if (i > 0 && i < n - 1) {
                internal_ge2 = true;
            }
        }
    }

    if (!any_ge2) {
        cout << -1 << endl;
    } else if (n == 2 or internal_ge2) {
        cout << sum - 1 << endl;
    } else {
        cout << sum - (n - 1) << endl;
    }
}

int main() {
    SpeedxKH;

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}