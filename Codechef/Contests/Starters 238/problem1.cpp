#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y,z;
    cin>>x>>y>>z;
    int aus_total_score = x+z;

    if ( aus_total_score > y )
    {
        cout << (aus_total_score - y)+1 << endl;
    }
    else if ( aus_total_score == y )
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    


    return 0;
}