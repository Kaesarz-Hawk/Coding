// Author  : Kaesarz
// Date    : 30-06-2026
// Time    : 20:35

#include <bits/stdc++.h>
using namespace std;
#define ll      long long
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD  = 1e9 + 7;
const int INF  = 1e9;
const ll  LLINF = 1e18;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        if (x % y == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main() {
    SpeedxKH

    solve();

    return 0;
}