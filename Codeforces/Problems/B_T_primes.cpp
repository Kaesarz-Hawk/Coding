// Author  : Kaesarz
// Date    : 22-07-2026
// Time    : 18:33

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'
#define SpeedxKH ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;
const double EPS = 1e-9;
const int SIEVE_SIZE = 1000001;
bool is_prime[SIEVE_SIZE];

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

const int dx8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void solve()
{
    ll n;
    cin >> n;
    vector<ll> primes(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> primes[i];
    }
    for (ll i = 0; i < n; i++)
    {
        ll sq = (ll)sqrt((double)primes[i]);
        if (sq * sq == primes[i] && is_prime[sq])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}

int main()
{
    SpeedxKH


        is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i < SIEVE_SIZE; i++)
    {
        if (is_prime[i])
        {
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