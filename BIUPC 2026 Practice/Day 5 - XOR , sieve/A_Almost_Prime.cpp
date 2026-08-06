// Author  : Kaesarz
// Date    : 04-08-2026
// Time    : 12:01

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

bool isPrime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;

    int almostPrimeCount = 0;

    for (int i = 1; i <= n; i++)
    {
        int primeFactors = 0;

        for (int p = 2; p <= i; p++)
        {

            if (i % p == 0 && isPrime(p))
            {
                primeFactors++;
            }
        }

        if (primeFactors == 2)
        {
            almostPrimeCount++;
        }
    }

    cout << almostPrimeCount << "\n";
}

int main()
{
    SpeedxKH

    // int t;
    // cin >> t;
    // while (t--){ solve(); }

    // single test case
    solve();

    return 0;
}