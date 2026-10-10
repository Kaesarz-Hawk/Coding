// Author  : Kaesarz
// Date    : 10-10-2026
// Time    : 21:25

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
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pair<int , int>> combined(n);
    for(int i = 0; i < n; i++) {
        combined[i] ={a[i] , b[i]};
    }

    sort(combined.begin(), combined.end());
    cout << "Combined pairs: ";
    for(auto &p : combined) {
        cout << "(" << p.first << ", " << p.second << ") ";
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