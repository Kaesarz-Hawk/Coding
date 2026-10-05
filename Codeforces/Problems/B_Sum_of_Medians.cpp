// Author  : Kaesarz
// Date    : 06-10-2026
// Time    : 01:06

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n*k);
    for (int i = 0; i < n*k; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int x = n - (n + 1) / 2; 


    ll sum_of_medians = 0;
    for (int i = 0; i < k; i++) {
        
        sum_of_medians += a[(n * k) - 1 - x - i * (x + 1)];
    }
    cout << sum_of_medians << endl;
}

int main() {
    SpeedxKH;

     int t;
     cin >> t;
    while (t--) solve();



    return 0;
}