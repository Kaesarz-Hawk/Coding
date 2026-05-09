#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        vector<int> final_a_set(n);

        int l = 0, r = n - 1;

        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                final_a_set[i] = a[l];
                l++;
            }
            else{
                final_a_set[i] = a[r];
                r--;
            }
        }

        for(int i = 0; i < n; i++){
            cout << final_a_set[i] << " ";
        }
        cout << endl;
    }

    return 0;
}