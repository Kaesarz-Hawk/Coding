// Author  : Kaesarz
// Date    : 31-05-2026
// Time    : 18:55
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
   bool isLucky = false;
   vector<int> luckyNumbers = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
   for (int lucky : luckyNumbers) {
       if (n % lucky == 0) {
           isLucky = true;
           break;
       }
   }
    if (isLucky) {
         cout << "YES\n";
    } else {
         cout << "NO\n";
    }
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