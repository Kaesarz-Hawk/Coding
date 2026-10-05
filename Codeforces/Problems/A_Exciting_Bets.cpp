// Author  : Kaesarz
// Date    : 04-10-2026
// Time    : 14:40

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    ll a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0 << " " << 0 << endl;
        return;
    }

    
    ll max_gcd = abs(a - b);

    
    ll decrease_moves = a % max_gcd;

    
    ll increase_moves = max_gcd - decrease_moves;

    
    ll min_moves = min(decrease_moves, increase_moves);

    cout << max_gcd << " " << min_moves << endl;
}

int main() {
    SpeedxKH;

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}