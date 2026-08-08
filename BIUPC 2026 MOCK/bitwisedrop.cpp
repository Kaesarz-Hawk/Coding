// Author  : Kaesarz
// Date    : 08-08-2026
// Time    : 17:12

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

    bool sorted = false;
    is_sorted(a.begin(), a.end()) ? sorted = true : sorted = false;
    if (sorted) {
        cout << 0 << endl;
        return;
    }
    else {
        int operation = 0;
        for (int i = n - 1; i > 0; i--) {
          if (a[i-1] >= a[i])
           {
            a[i-1]--;
              operation++;
            }
        }
        cout << operation << endl;
    }

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