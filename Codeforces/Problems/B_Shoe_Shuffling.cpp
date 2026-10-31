// Author  : Kaesarz
// Date    : 30-10-2026
// Time    : 03:12

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
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0;
    while (l < n) {
        int r = l;
        while (r < n && a[r] == a[l]) {
            r++;
        }
        int count = r - l;
        if (count == 1) {
            cout << -1 << endl;
            return;
        }

        for (int i = l; i < r - 1; i++) {
            a[i] = i + 2;
        }
        a[r - 1] = l + 1;

        l = r;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    SpeedxKH;

    int t;
     cin >> t;
    while (t--) solve();

    
    return 0;
}