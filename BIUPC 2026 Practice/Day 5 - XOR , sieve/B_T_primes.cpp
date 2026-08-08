// Author  : Kaesarz
// Date    : 07-08-2026
// Time    : 02:13

#include <bits/stdc++.h>
using namespace std;
#define ll      long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD  = 1e9 + 7;
const int INF  = 1e9;
const ll  LLINF = 1e18;

const int MAXN = 1e6 + 5; 
bool isComposite[MAXN];

void sieve() {
    isComposite[0] = isComposite[1] = true;
    for (int i = 2; i < MAXN; i++) {
        if (!isComposite[i]) {
            for (long long j = (long long)i * i; j < MAXN; j += i) {
                isComposite[j] = true;
            }
        }
    }
}

void solve() {
    long long x;
    cin >> x;

    long long r = sqrt(x);

    if (r * r == x and r >= 2 and !isComposite[r]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    SpeedxKH
    sieve();

    int t;
    cin >> t;
    while (t--) { 
        solve(); 
    }

    return 0;
}