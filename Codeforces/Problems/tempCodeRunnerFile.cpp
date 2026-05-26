#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define speedxKH                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int gcd(int a, int b)
{
    while (b != 0)
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main()
{
    speedxKH;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        bool found = false;

        for (int i = 0; i < n and !found; i++)
        {
            for (int j = i + 1; j < n and !found; j++)
            {
                if (gcd(a[i], a[j]) <= 2)
                {
                    found = true;
                }
            }
        }
        found ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}