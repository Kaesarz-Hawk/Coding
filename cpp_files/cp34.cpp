#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;  
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    long long current_sum = 0;
    int count = 0;

   
    for (int i = 0; i < n; i++) {
        if (current_sum + a[i] >= 0) {
            current_sum += a[i];
            count++;
        } else {
            
            break;
        }
    }

    cout << count << endl;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}