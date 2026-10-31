// Author  : Kaesarz
// Date    : 31-10-2026
// Time    : 21:24

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
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if (i % 2 == 0) {
            b[i] = a;
        } else {
            b[i] = -a;
        }
    }

    sort(b.rbegin(), b.rend());

    ll max_sum = 0;
    int pos_count = (n + 1) / 2;

    for (int i = 0; i < n; i++) {
        if (i < pos_count) {
            max_sum += b[i];
        } else {
            max_sum -= b[i];
        }
    }

    cout << max_sum << endl;
}

int main() {
    SpeedxKH;

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}