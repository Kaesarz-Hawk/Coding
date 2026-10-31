// Author  : Kaesarz
// Date    : 31-10-2026
// Time    : 20:43

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    int rock_x;
    int scissors_y;
    int paper_z;
    cin >> rock_x >> scissors_y >> paper_z;

    int total = rock_x + scissors_y + paper_z;

    if (scissors_y >= paper_z) {
      
        cout << string(total, 'R') << endl;
    } else if (paper_z >= rock_x) {
    
        cout << string(total, 'S') << endl;
    } else {
      
        cout << string(total, 'P') << endl;
    }
}

int main() {
    SpeedxKH;

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}