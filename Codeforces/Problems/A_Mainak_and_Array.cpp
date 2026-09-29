// Author  : Kaesarz
// Date    : 29-09-2026
// Time    : 20:23

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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    
    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    
    int max_val = *max_element(arr.begin() + 1, arr.end());
    int res1 = max_val - arr[0];

    
    int min_val = *min_element(arr.begin(), arr.end() - 1);
    int res2 = arr[n - 1] - min_val;

    
    int res3 = -INF;
    for (int i = 0; i < n - 1; i++) {
        res3 = max(res3, arr[i] - arr[i + 1]);
    }

    
    cout << max({res1, res2, res3}) << endl;
}

int main() {
    SpeedxKH;

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}