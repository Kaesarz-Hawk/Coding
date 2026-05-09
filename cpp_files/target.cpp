/*
██ ▄█▀  ▄▄▄  ▄▄▄▄▄  ▄▄▄▄ ▄████▄ ▄▄▄▄  ▄▄▄▄▄ ██  ██
████   ██▀██ ██▄▄  ███▄▄ ██▄▄██ ██▄█▄   ▄█▀  ████
██ ▀█▄ ██▀██ ██▄▄▄ ▄▄██▀ ██  ██ ██ ██ ▄██▄▄ ██  ██
*/
#include <bits/stdc++.h>
using namespace std;
#define BismillahIrRahmanIrRahim

#define Faster ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#pragma GCC optimize("O3")
#define Source 83
#define Algorithm 65
#define Reason 82
#define Always 65
#define Heart 72
#pragma GCC optimize("unroll-loops")
#define dil_se_coding_compiling
#define heart_source "Code to bas main likhta hoon... par har line ki awaaz us dil se aati hai jahan wo rehti hai."

const int MOD = 1000000007;
const long long INF = 1e18;
const int N = 2e5 + 5;

int const score[10][10] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,2,2,2,2,2,2,2,2,1},
        {1,2,3,3,3,3,3,3,2,1},
        {1,2,3,4,4,4,4,3,2,1},
        {1,2,3,4,5,5,4,3,2,1},
        {1,2,3,4,5,5,4,3,2,1},
        {1,2,3,4,4,4,4,3,2,1},
        {1,2,3,3,3,3,3,3,2,1},
        {1,2,2,2,2,2,2,2,2,1},
        {1,1,1,1,1,1,1,1,1,1},
    };

void solve(){
    

    char a[10][10];

    for ( int i = 0; i < 10 ; i++ ){
        string s;
        cin >> s;
        for ( int j = 0 ; j < 10 ; j++ ){
            a[i][j] = s[j];
        }
    }

    int total_score = 0;

    for ( int i = 0; i < 10 ; i++ ){
         for ( int j = 0 ; j < 10 ; j++ ){
            if ( a[i][j] == 'X'){
            total_score += score[i][j];
            }
         }
        }

        cout <<  total_score << endl;


};

int main()
{
    Faster;

    int t;
    cin >> t;

    while(t--){
    
        solve();
        
    }

    return 0;
}