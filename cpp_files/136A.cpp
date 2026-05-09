#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin >> n;
    vector<int> array(n);

    for ( int i = 0 ; i <n ; i++){
        cin >> array[i];
    }

    for ( int j = 1; j <=n ; j++){
        for( int i = 0 ; i <n ; i++)
        {
            if ( array[i] == j)
            {
                cout << i+1 << " ";
            }
        }
    }


    return 0;
}