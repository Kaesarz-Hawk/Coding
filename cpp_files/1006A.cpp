#include<bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        bool found = false;

        for(int l_mid = 1; l_mid < n-1; l_mid++){
            for(int r_last = l_mid+1; r_last < n; r_last++){

                vector<int> s1;
                for(int i=0; i<l_mid; i++){
                    s1.push_back(a[i]);
                }

                vector<int> s2;
                for(int i=l_mid; i<r_last; i++){
                    s2.push_back(a[i]);
                }

                vector<int> s3;
                for(int i=r_last; i<n; i++){
                    s3.push_back(a[i]);
                }

                int sum1 = accumulate(s1.begin(), s1.end(), 0);
                int sum2 = accumulate(s2.begin(), s2.end(), 0);
                int sum3 = accumulate(s3.begin(), s3.end(), 0);

                int modus1 = sum1 % 3;
                int modus2 = sum2 % 3;
                int modus3 = sum3 % 3;

                if(modus1 == modus2 && modus2 == modus3){
                    cout << l_mid << " " << r_last << endl;
                    found = true;
                    break;
                }

                if(modus1 != modus2 && modus1 != modus3 && modus2 != modus3){
                    cout << l_mid << " " << r_last << endl;
                    found = true;
                    break;
                }
            }

            if(found){
                break;
            }
        }

        if(found == false){
            cout << 0 << " " << 0 << endl;
        }
    }

    return 0;
}