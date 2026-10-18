// Author  : Kaesarz
// Date    : 18-10-2026
// Time    : 21:11

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

    ll largest_proper_divisor = 1;
    ll d = largest_proper_divisor;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
        d = n / i;
        break;
        }
    }

    cout << d << " " << n - d << endl;


}

int main() {
    SpeedxKH;

    int t;
     cin >> t;
     while (t--) solve();



    return 0;
}