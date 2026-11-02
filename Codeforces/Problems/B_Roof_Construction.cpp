// Author  : Kaesarz
// Date    : 03-11-2026
// Time    : 01:58

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    int n;
    cin >> n;
    
    // 1. Create vector permutation(n) with values 0 to n-1
    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        permutation[i] = i;
    }


  int k = 1;
    
    for (int i = 1; i < n; i++) {
        if (permutation[i] == k * 2) {
            k = permutation[i];
        }
    }

  
    for (int i = k - 1; i >= 0; i--) {
        cout << permutation[i] << " ";
    }
    for (int i = k; i < n; i++) {
        cout << permutation[i] << " ";
    }
    cout << endl;
}

int main()
{
    SpeedxKH;

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}