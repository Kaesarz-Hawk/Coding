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

int main()
{
    Faster;

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        string s;
        cin >> s;

        for (int i = 0; i < s.size(); i++)
        {
            s[i] = tolower(s[i]);
        }

        string ans;

        ans += s[0];

        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != s[i - 1])
            {
                ans += s[i];
            }
        }

        if (ans == "meow")
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}