// Author  : Kaesarz
// Date    : 25-07-2026
// Time    : 05:36

#include <bits/stdc++.h>
using namespace std;
#define ll      long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD  = 1e9 + 7;
const int INF  = 1e9;
const ll  LLINF = 1e18;

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<ll> pre(n+1);
    for(int i= n-k+1; i<=n; i++)
    {
        cin >> pre[i];
    }

    if (k == 1)
    {
        cout << "Yes\n";
        return;
    }

    vector<ll> a(n+1);
    for(int i= n-k+2; i<=n; i++){
        a[i] = pre[i] - pre[i-1];
    }

    for(int i= n-k+2; i<n; i++){
        if(a[i] > a[i+1]){
            cout << "No\n";
            return;
        }
    }

    if (pre[n-k+1] <= a[n-k+2] * (n-k+1))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
 
}

int main() {
    SpeedxKH

     int t;
     cin >> t;
     while (t--){ solve(); }

    // single test case
    // solve();

    return 0;
}