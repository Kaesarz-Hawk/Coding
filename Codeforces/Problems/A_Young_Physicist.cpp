// Author  : Kaesarz
// Date    : 03-11-2026
// Time    : 03:20

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
    
    int sum_x = 0, sum_y = 0, sum_z = 0;
    while (n != 0) {
        int x, y, z;
        cin >> x >> y >> z;
        sum_x += x;
        sum_y += y;
        sum_z += z;
        n--;
    }

    if (sum_x == 0 && sum_y == 0 && sum_z == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    SpeedxKH;

    // int t;
    // cin >> t;
    // while (t--) solve();

    // single test case
    solve();

    return 0;
}