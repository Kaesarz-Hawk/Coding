// Author  : Kaesarz
// Date    : 23-07-2026
// Time    : 12:14

#include <bits/stdc++.h>
using namespace std;
#define ll      long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD  = 1e9 + 7;
const int INF  = 1e9;
const ll  LLINF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int odd_count = 0, even_count = 0;
    int odd_index = -1, even_index = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            even_count++;
            if (even_index == -1) even_index = i + 1;
        } else {
            odd_count++;
            if (odd_index == -1) odd_index = i + 1;
        }
    }

    cout << (odd_count == 1 ? odd_index : even_index) << endl;
 
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