// Author  : Kaesarz
// Date    : 20-10-2026
// Time    : 03:18

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
    char c;
    cin >> n >> c;
    string s;
    cin >> s;

    string t = s + s;

    if (c == 'g') {
        cout << 0 << endl;
        return;
    }

    int max_wait = 0;
    int slow = 0;

    for (int fast = 0; fast < 2 * n; fast++) {
        if (t[fast] == 'g') {
            while (slow <= fast && slow < n) {
                if (t[slow] == c) {
                    max_wait = max(max_wait, fast - slow);
                }
                slow++;
            }
        }
    }

    cout << max_wait << endl;
}

int main() {
    SpeedxKH;

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}