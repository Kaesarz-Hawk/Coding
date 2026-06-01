// Author  : Kaesarz
// Date    : 01-06-2026
// Time    : 21:16

#include <bits/stdc++.h>
using namespace std;
#define ll      long long
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD  = 1e9 + 7;
const int INF  = 1e9;
const ll  LLINF = 1e18;

void solve() {
    int a, b;
    cin >> a >> b;
    int xK, yK;
    cin >> xK >> yK;
    int xQ, yQ;
    cin >> xQ >> yQ;

    int dx[] = {a, a, -a, -a, b, b, -b, -b};
    int dy[] = {b, -b, b, -b, a, -a, a, -a};

    int count = 0;
    int limit = (a == b) ? 4 : 8;
    for (int i = 0; i < limit; i++) {
        int px = xK + dx[i];
        int py = yK + dy[i];
        if ((abs(px - xQ) == a && abs(py - yQ) == b) || 
            (abs(px - xQ) == b && abs(py - yQ) == a)) {
            count++;
        }
    }
    cout << count << "\n";
}

int main() {
    SpeedxKH

     int t;
     cin >> t;
     while (t--){ solve(); }

    // single test case
    // solve();

    return 0;
}