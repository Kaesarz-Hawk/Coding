// Author  : Kaesarz
// Date    : 02-07-2026
// Time    : 09:51

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    ll n;
    cin >> n;

    vector<ll> arr(n);


    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    if (n % 2 == 0) {

  
        cout << 2 << "\n";
        cout << 1 << " " << n << "\n";
        cout << 1 << " " << n << "\n";
    }

    else {
  
        cout << 4 << "\n";
        cout << 1 << " " << n - 1 << "\n";
        cout << 1 << " " << n - 1 << "\n";
        cout << n - 1 << " " << n << "\n";
        cout << n - 1 << " " << n << "\n";
    }
}

int main() {
    SpeedxKH

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}