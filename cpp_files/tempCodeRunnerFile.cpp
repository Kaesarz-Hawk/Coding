#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
     int a,b,c,d;
        cin >> a >> b >> c >> d;
        //walkling master
        // move 1 right top = (a+1 , b+1);
       // move 2 left = (a-1, b);
        int count = 0;
    
      if ( a == c and b == d) {
        cout << 0 << endl;
        continue;
      }
      if ( b > d)
      cout << -1 << endl;
      break;

      int shift = d - b;
      if ( a < c - shift) {
        cout << -1 << endl;
        break;
      }
      else {
        int ans = a-c+shift+shift;
        cout << ans << endl;
      }
      
    }
return 0;

}

