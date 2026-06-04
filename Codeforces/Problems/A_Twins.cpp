// Author  : Kaesarz
// Date    : 04-06-2026
// Time    : 18:12

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

        vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

   
  int total = accumulate(a.begin(), a.end(), 0);

int my_sum = 0;
int cnt = 0;

for (int i = n - 1; i >= 0; i--) {
    my_sum += a[i];
    cnt++;

    if (my_sum > total - my_sum) {
        cout << cnt << endl;
        return;
    }
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