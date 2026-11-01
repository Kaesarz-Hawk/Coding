// Author  : Kaesarz
// Date    : 01-11-2026
// Time    : 23:43

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    string s;
    cin >> s;
    vector<int> numbers;
    for (int i = 0; i < s.length(); i += 2) {
        numbers.push_back(s[i] - '0');
    }
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size(); i++) {
        if (i > 0) cout << '+';
        cout << numbers[i];
    }
    cout << endl;
}

int main() {
    SpeedxKH;

    // int t;
    // cin >> t;
    // while (t--) solve();

    // single test case
    solve();

    return 0;
}