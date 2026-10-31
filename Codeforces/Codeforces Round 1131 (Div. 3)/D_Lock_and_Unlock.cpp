// Author  : Kaesarz
// Date    : 31-10-2026
// Time    : 21:09

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
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll median = a[n / 2];
    ll min_cost = 0;
    for (int i = 0; i < n; i++) {
        min_cost += abs(a[i] - median);
    }

    ll min_ops = a[n - 1] - a[0];

    cout << min_cost << " " << min_ops << endl;
}

int main() {
    SpeedxKH;

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}