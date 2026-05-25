#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000003;
int main() {
    int T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        ll ans = 0;
        for (ll i = 1; i <= n; i++) {
            ans = (ans + (ll)pow((i * (i + 1)) / 2.0, 2)) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
