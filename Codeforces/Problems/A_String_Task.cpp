// Author  : Kaesarz
// Date    : 03-11-2026
// Time    : 03:04

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

    for (char &c : s) {
        c = tolower(c);
    }

    char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    

      for (char c : vowels) {
        erase(s, c);
    }
    

    for (char c : s) {
        cout << '.' << c;
    }
    cout << endl;
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