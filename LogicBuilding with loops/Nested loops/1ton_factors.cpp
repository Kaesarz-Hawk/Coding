// Author  : Kaesarz
// Date    : 16-09-2026
// Time    : 10:43

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int count = 0;

        // Check divisors up to sqrt(i)
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                // If j divides i, then both j and (i/j) are factors
                if (j * j == i)
                {
                    count += 1; // Perfect square case, don't double count
                }
                else
                {
                    count += 2; // Add both j and i/j
                }
            }
        }
        cout << "Factors of " << i << ": " << count << endl;
    }
    
}

int main()
{
    SpeedxKH;

    // int t;
    // cin >> t;
    // while (t--) solve();

    // single test case
    solve();

    return 0;
}