// Author  : Kaesarz
// Date    : 13-10-2026
// Time    : 23:21

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    if (s1 < s2) {
        cout << "-1" << endl;
    } else if (s1 > s2) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
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