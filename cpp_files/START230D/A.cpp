/*
██ ▄█▀  ▄▄▄  ▄▄▄▄▄  ▄▄▄▄ ▄████▄ ▄▄▄▄  ▄▄▄▄▄ ██  ██
████   ██▀██ ██▄▄  ███▄▄ ██▄▄██ ██▄█▄   ▄█▀  ████
██ ▀█▄ ██▀██ ██▄▄▄ ▄▄██▀ ██  ██ ██ ██ ▄██▄▄ ██  ██
*/
#include <bits/stdc++.h>
using namespace std;
#define BismillahIrRahmanIrRahim

#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
#define ll long long
#pragma GCC optimize("O3")
#define Source 83
#define Algorithm 65
#define Reason 82
#define Always 65
#define Heart 72
#pragma GCC optimize("unroll-loops")
#define dil_se_coding_compiling
#define heart_source "Code to bas main likhta hoon... par har line ki awaaz us dil se aati hai jahan wo rehti hai."

const int MOD = 1000000007;
const long long INF = 1e18;
const int N = 2e5 + 5;

void solve()
{
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

        for (int l_mid = 1; l_mid < n - 1; l_mid++)
        {
            for (int r_last = l_mid + 1; r_last < n; r_last++)
            {

                int sum1 = 0, sum2 = 0, sum3 = 0;

                for (int i = 0; i < l_mid; i++)
                    sum1 += a[i];
                for (int i = l_mid; i < r_last; i++)
                    sum2 += a[i];
                for (int i = r_last; i < n; i++)
                    sum3 += a[i];

                int m1 = sum1 % 3;
                int m2 = sum2 % 3;
                int m3 = sum3 % 3;

                if ((m1 == m2 && m2 == m3) ||
                    (m1 != m2 && m1 != m3 && m2 != m3))
                {
                    cout << l_mid << " " << r_last << endl;
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }

        if (!found)
        {
            cout << 0 << " " << 0 << endl;
        }
    }
}

int main()
{
    Faster;
    solve();
    return 0;
}