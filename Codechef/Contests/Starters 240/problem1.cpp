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
        int x , y , a , b   ;
        cin >> x >> y >> a >> b;

        if (x > a)
        {
            cout << "Alice" << endl;
        }
        else if (a > x)
        {
            cout << "Bob" << endl;
        }
        else
        {
            if (y >= b)
            {
                cout << "Alice" << endl;
            }
            else
            {
                cout << "Bob" << endl;
            }
        }
    }

    return 0;
}