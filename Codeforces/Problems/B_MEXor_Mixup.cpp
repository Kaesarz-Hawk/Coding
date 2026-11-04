// Author  : Kaesarz
// Date    : 04-11-2026
// Time    : 21:58

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

int getXOR(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

void solve() {
    int a,b;
    cin >> a >> b;
    
    
    int xor_of_all_X = getXOR(a-1);
  

    int ans =0;

    if (xor_of_all_X == b) {
        ans = a;
    }
    else {
        
        if((xor_of_all_X ^ b) == a) {
            ans = a+2;
        }
        else {
            ans = a+1;
        }
    }



    cout << ans << endl;


}

int main() {
    SpeedxKH;

 int t;
 cin >> t;
 while (t--) solve();


    return 0;
}