// Author  : Kaesarz
// Date    : 03-10-2026
// Time    : 17:51

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    ll n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll cnt1 = 0;
    ll cnt0 = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            cnt1++;
        } else if (a[i] == 0) {
            cnt0++;
        }
    }

    ll ans = cnt1 * pow(2, cnt0);
    cout << ans << endl;

}

int main() {
    SpeedxKH;

     int t;
    cin >> t;
    while (t--) solve();

    

    return 0;
}