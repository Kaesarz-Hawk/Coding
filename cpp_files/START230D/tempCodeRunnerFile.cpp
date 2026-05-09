/*
██ ▄█▀  ▄▄▄  ▄▄▄▄▄  ▄▄▄▄ ▄████▄ ▄▄▄▄  ▄▄▄▄▄ ██  ██
████   ██▀██ ██▄▄  ███▄▄ ██▄▄██ ██▄█▄   ▄█▀  ████
██ ▀█▄ ██▀██ ██▄▄▄ ▄▄██▀ ██  ██ ██ ██ ▄██▄▄ ██  ██
*/
#include <bits/stdc++.h>
using namespace std;
#define BismillahIrRahmanIrRahim

#define Faster ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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

void solve(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
    
        for (int i = 1; i <= n; i++)
        {
            cout << i << " " << n + 2 * i - 1 << " " << n + 2 * i;
            if (i < n)
            cout << " ";
        }
        cout << "\n";
}

}

int main()
{
    Faster;

    solve();

    return 0;
}