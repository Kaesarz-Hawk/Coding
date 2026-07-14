// Author  : Kaesarz
// Date    : 14-07-2026
// Time    : 20:35

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

    string s;
    cin >> s;

    int mx = 0;
    int count = 0;

    for (char c : s) {
        if (c == '#') {
            count++;
        }
        else {
            mx = max(mx, (count + 1) / 2);
            count = 0;
        }
    }

    mx = max(mx, (count + 1) / 2);

    cout << mx << "\n";
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