// Author  : Kaesarz
// Date    : 05-06-2026
// Time    : 12:02

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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int xor_sum = 0;
    for (int i = 0; i < n; i++) {
        xor_sum ^= arr[i];
    }
    if (n % 2 == 1) {
        cout << xor_sum << endl;
    } 

    else {
        if (xor_sum == 0) 
            cout << xor_sum << endl;
        else 
            cout << -1 << endl;
        
    }
}

int main() {
    SpeedxKH

     int t;
     cin >> t;
     while (t--){ solve(); }

    // single test case
    //solve();

    return 0;
}