// Author  : Kaesarz
// Date    : 16-09-2026
// Time    : 11:48

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

    for ( int a = 1; a <=n ; a++)
    {
        for ( int b = a+1 ; b <= n ; b++){
            int c2 = a*a + b*b;
            int c = sqrt(c2);
            if (c*c == c2 && c <= n) {
                cout << a << " " << b << " " << c << endl;
            }
        }
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