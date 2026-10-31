// Author  : Kaesarz
// Date    : 31-10-2026
// Time    : 20:38

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    string p, q;
    cin >> p >> q;

    q += "six";

    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    if (p == q) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    SpeedxKH;

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}