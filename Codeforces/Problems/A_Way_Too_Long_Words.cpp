// Author  : Kaesarz
// Date    : 01-11-2026
// Time    : 23:39

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    string s;
    cin >> s;
    if (s.length() > 10) {
        cout << s[0] << s.length() - 2 << s[s.length() - 1] << endl;
    } else {
        cout << s << endl;
    }
}

int main() {
    SpeedxKH;

 int t;
 cin >> t;
 while (t--) solve();

  

    return 0;
}