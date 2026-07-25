// Author   : Kaesarz
// Date     : 25-07-2026

#include <bits/stdc++.h>
using namespace std;
#define ll      long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    
    vector<ll> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    int operations = 0;

    
    priority_queue<ll> max_pq;
    ll sum = 0;
    for (int i = m - 1; i >= 1; i--) {
        sum += a[i];
        if (a[i] > 0) {
            max_pq.push(a[i]);
        }
        while (sum > 0) {
            ll x = max_pq.top();
            max_pq.pop();
            sum -= 2 * x;
            operations++;
        }
    }

    
    priority_queue<ll, vector<ll>, greater<ll>> min_pq;
    sum = 0;
    for (int i = m; i < n; i++) {
        sum += a[i];
        if (a[i] < 0) {
            min_pq.push(a[i]);
        }
        while (sum < 0) {
            ll x = min_pq.top();
            min_pq.pop();
            sum -= 2 * x;
            operations++;
        }
    }

    cout << operations << endl;
}

int main() {
    SpeedxKH

    int t;
    cin >> t;
    while (t--) { 
        solve(); 
    }

    return 0;
}