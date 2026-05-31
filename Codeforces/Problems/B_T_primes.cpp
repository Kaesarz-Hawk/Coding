// Author  : Kaesarz
// Date    : 31-05-2026
// Time    : 21:18
#include <bits/stdc++.h>
using namespace std;
#define ll      long long
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);
const int MOD  = 1e9 + 7;
const int INF  = 1e9;
const ll  LLINF = 1e18;

const int SIEVE_SIZE = 1e6 + 1;
vector<bool> is_prime(SIEVE_SIZE, true);

void solve() {
    ll n;
    cin >> n;
    vector<ll> primes(n);

    for (ll i = 0; i < n; i++) {
        cin >> primes[i];
    }
    for (ll i = 0; i < n; i++) {
        ll sq = (ll)sqrt((double)primes[i]);
        if (sq * sq == primes[i] && is_prime[sq]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    SpeedxKH
 
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i < SIEVE_SIZE; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j < SIEVE_SIZE; j += i)
                is_prime[j] = false;
        }
    }
    // int t;
    // cin >> t;
    // while (t--){ solve(); }
    // single test case
    solve();
    return 0;
}