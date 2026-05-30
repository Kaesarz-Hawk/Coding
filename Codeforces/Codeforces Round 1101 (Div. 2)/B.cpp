#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main()
{
    SpeedxKH;
 
    int t;
    cin >> t;
 
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
 
        ll current_sum = 0;
        
        ll min_height = a[0];
 
        for (int i = 0; i < n; i++)
        {
            current_sum += a[i];
 
            ll possible_height = current_sum / (i + 1);
 
            if (possible_height < min_height){
 
                min_height = possible_height;
            }
 
            cout << min_height << " ";
        }
 
        cout << "\n";
    }
    return 0;
}
