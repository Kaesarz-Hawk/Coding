// Author  : Kaesarz
// Date    : 06-10-2026
// Time    : 14:04

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

    int total_moves = 0;


    while (s.length() >= 2) {
        bool found = false;
        for (int i = 0; i < (int)s.length() - 1; i++) {
            if (s[i] != s[i + 1]) {
                s.erase(i, 2); 
                total_moves++;
                found = true;
                break;
            }
        }
        
        
        if (!found) break; 
    }

    if (total_moves % 2 != 0) {
        cout << "DA" << endl;
    } else {
        cout << "NET" << endl;
    }
}

int main() {
    SpeedxKH;

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}