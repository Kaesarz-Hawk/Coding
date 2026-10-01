// Author  : Kaesarz
// Date    : 01-10-2026
// Time    : 16:26

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    
    sort(a.begin(), a.end());

    int mx_freq = 1, current_freq = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            current_freq++;
        } else {
            current_freq = 1;
        }
        mx_freq = max(mx_freq, current_freq);
    }

    
    int ans = 0;
    while (mx_freq < n) {
        int swap = min(n - mx_freq, mx_freq);  
        ans += 1 + swap;             
        mx_freq += swap;                  
    }

    cout << ans << endl;
}

int main() {
    SpeedxKH;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}