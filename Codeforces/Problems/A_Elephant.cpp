// Author  : Kaesarz
// Date    : 04-06-2026
// Time    : 18:03

#include <bits/stdc++.h>
using namespace std;
#define ll      long long
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD  = 1e9 + 7;
const int INF  = 1e9;
const ll  LLINF = 1e18;

void solve() {
    int n;
    cin >> n;

    int steps = 0;
    while (n > 0) {
        if (n >= 5) {
            n -= 5;
        } else if (n >= 4) {
            n -= 4;
        } else if (n >= 3) {
            n -= 3;
        } else if (n >= 2) {
            n -= 2;
        } else {
            n -= 1;
        }
        steps++;
    }
    cout << steps << endl;
}

int main() {
    SpeedxKH

    // int t;
    // cin >> t;
    // while (t--){ solve(); }

    // single test case
    solve();

    return 0;
}