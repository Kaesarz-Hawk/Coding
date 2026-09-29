// Author  : Kaesarz
// Date    : 29-09-2026
// Time    : 21:28

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    long long n;
    cin >> n;

    if (n % 2 != 0 || n < 4) {
        cout << -1 << '\n';
        return;
    }

    long long minBuses = (n + 5) / 6; 
    long long maxBuses = n / 4;   

    cout << minBuses << ' ' << maxBuses << '\n';
}

int main() {
    SpeedxKH;

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}