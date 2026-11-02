// Author  : Kaesarz
// Date    : 02-11-2026
// Time    : 04:21

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    int n,r,b;
    
    cin >> n >> r >> b;

    string s;
   
    int win_row = r / (b+1)   ;
    int extra_r = r % (b+1)  ;



    for(int i = 0; s.length() < n; i++) {
          int r_count = win_row;
        while(r_count) {
            s += 'R';
            r_count--;
            
        }
        if(extra_r > 0) {
            s += 'R';
            extra_r--;
        }
        if(s.length() < n) {
            s += 'B';   
        }
   
    }        

cout << s << endl;

}

int main() {
    SpeedxKH;

     int t;
     cin >> t;
     while (t--) solve();

    

    return 0;
}