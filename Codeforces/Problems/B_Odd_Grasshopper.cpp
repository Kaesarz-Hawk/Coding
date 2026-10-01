// Author  : Kaesarz
// Date    : 01-10-2026
// Time    : 16:50

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    ll postion_x0, jump_n;
    cin >> postion_x0 >> jump_n;

    bool even = false;
    bool odd = false;
    
    if (abs(postion_x0) % 2 == 0) {
        even = true;
    } else {
        odd = true;
    }


    ll rem = jump_n % 4;
    ll offset = 0;

    if (rem == 1) {
        offset = -jump_n;
    } else if (rem == 2) {
        offset = 1;
    } else if (rem == 3) {
        offset = jump_n + 1;
    } else if (rem == 0) {
        offset = 0;
    }

 
    if (odd) {
        offset = -offset;
    }

    cout << postion_x0 + offset << endl;
}

int main() {
    SpeedxKH;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}