// Author  : Kaesarz
// Date    : 03-11-2026
// Time    : 18:55

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {


    ll w, h;
    cin >> w >> h;

    int k1;
    cin >> k1;
    vector<int>wall1(k1);
    for (int i = 0; i < k1; i++) {
        cin >> wall1[i];
    }
    int k2;
    cin >> k2;
    vector<int>wall2(k2);
    for (int i = 0; i < k2; i++) {
        cin >> wall2[i];
    }
    int k3;
    cin >> k3;
    vector<int>wall3(k3);
    for (int i = 0; i < k3; i++) {
        cin >> wall3[i];
    }
    int k4;
    cin >> k4;
    vector<int>wall4(k4);
    for (int i = 0; i < k4; i++) {
        cin >> wall4[i];
    }

    double wallk1 = (wall1.back() - wall1.front()) * h / 2.0;
    double wallk2 = (wall2.back() - wall2.front()) * h / 2.0;
    double wallk3 = (wall3.back() - wall3.front()) * w / 2.0;
    double wallk4 = (wall4.back() - wall4.front()) * w / 2.0;

    double max_area = max({wallk1, wallk2, wallk3, wallk4});
    
 
    ll ans = max_area * 2;
    cout << ans << endl;
    
}

int main() {
    SpeedxKH;

     int t;
     cin >> t;
     while (t--) solve();

    

    return 0;
}