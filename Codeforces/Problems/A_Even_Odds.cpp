// Author  : Kaesarz
// Date    : 31-05-2026
// Time    : 19:31
#include <bits/stdc++.h>
using namespace std;
#define ll      long long
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);
const int MOD  = 1e9 + 7;
const int INF  = 1e9;
const ll  LLINF = 1e18;

void solve()
{
    long long n_naturalnumbers, k_position;
    cin >> n_naturalnumbers >> k_position;

    long long count_odds = (n_naturalnumbers + 1) / 2;

    long long answer;
    if (k_position <= count_odds)
        answer = 2 * k_position - 1;          
    else
        answer = 2 * (k_position - count_odds); 

    cout << answer << '\n';
}
   
int main() {
    SpeedxKH
    // int t;
    // cin >> t;
    // while (t--){ solve(); }
    // single test case
    solve();
    return 0;
}