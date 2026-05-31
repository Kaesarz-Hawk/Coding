// Author  : Kaesarz
// Date    : 31-05-2026
// Time    : 19:02

#include <bits/stdc++.h>
using namespace std;
#define ll      long long
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD  = 1e9 + 7;
const int INF  = 1e9;
const ll  LLINF = 1e18;

void solve() {
  
    ll n, m, a;
        cin >> n >> m >> a;

    ll flagstonesAlongLength = (n + a - 1) / a; 
    ll flagstonesAlongWidth = (m + a - 1) / a;

    ll totalFlagstones = flagstonesAlongLength * flagstonesAlongWidth;
    cout << totalFlagstones << "\n";
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