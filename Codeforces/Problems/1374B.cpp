#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SpeedxKH                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
void div6(ll &n, int &moves_count)
{
    n /= 6;
    moves_count++;
}
void mul2(ll &n, int &moves_count)
{
    n *= 2;
    moves_count++;
}

int main()
{
    SpeedxKH;
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        int moves_count = 0;

        while (n != 1)
        {
            if (n % 6 == 0)
            {
                div6(n, moves_count);
            }
            else if (n % 3 == 0)
            {
                mul2(n, moves_count);
            }
            else
            {
                moves_count = -1;
                break;
            }
        }

        cout << moves_count << endl;
    }
    return 0;
}