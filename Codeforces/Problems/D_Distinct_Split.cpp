// Author  : Kaesarz
// Date    : 20-10-2026
// Time    : 00:52

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> prefix(n , 0) , suffix(n , 0);
    set<char> st1, st2;

    for(int i = 0 ; i < n ; i++) {
        st1.insert(s[i]);
        prefix[i] = st1.size();
    }

    for(int i = n - 1 ; i >= 0 ; i--) {
        st2.insert(s[i]);
        suffix[i] = st2.size();
    }

    int max_distinct = 0;
    for(int i = 0 ; i < n - 1 ; i++) {
        max_distinct = max(max_distinct , prefix[i] + suffix[i + 1]);
    }

    cout << max_distinct << endl;   
}

int main() {
    SpeedxKH;

     int t;
     cin >> t;
     while (t--) solve();

   
    return 0;
}