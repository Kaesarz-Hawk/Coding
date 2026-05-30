#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main()
{
    faster;

    int t;
    cin >> t;

    while (t--)
    {
        int cakelen_n;
        cin >> cakelen_n;
        vector<ll> a(cakelen_n);
        for (int i = 0; i < cakelen_n; i++)
        {
            cin >> a[i];
        }

        ll current_sum = 0;

        ll min_height = a[0];

        for (int i = 0; i < cakelen_n; i++)
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