#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
cin >> t;
while(t--){
    
  int n;
  cin >> n;
  vector<int> vec(n);
  for(int i=0; i<n; i++)
    cin >> vec[i];

    sort(vec.begin(), vec.end());
    int sum = 0;
    for(int i=0; i<n-1; i++){
        sum += vec[i+1] - vec[i];
    }

    cout << sum << endl;

}
return 0;
}
