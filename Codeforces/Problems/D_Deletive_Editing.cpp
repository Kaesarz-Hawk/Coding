// Author  : Kaesarz
// Date    : 01-10-2026
// Time    : 00:50

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
    string s, t;
    cin >> s >> t;

    map<char, int> freqT;
    for (char c : t)
        freqT[c]++;

    string result = "";
    
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (freqT[s[i]] > 0)
        {
            result.push_back(s[i]);
            freqT[s[i]]--;
        }
    }

   
    reverse(result.begin(), result.end());

    if (result == t)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    SpeedxKH;

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}