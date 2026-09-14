#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n;
    cin >> n;
    string a, s;
    cin >> a >> s;

    // Count initial inversions
    ll inv = 0;
    int ones = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') ones++;
        else inv += ones;
    }

    // Count total ones and zeros
    int totalOnes = ones;
    int totalZeros = n - totalOnes;

    // Position of each 1 and 0 (0-indexed)
    vector<int> pos1, pos0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') pos1.push_back(i);
        else pos0.push_back(i);
    }

    // Two pointers for processed elements
    int p1 = 0;  // how many 1s have been processed (moved to the right)
    int p0 = 0;  // how many 0s have been processed (moved to the left)

    cout << inv;

    for (int op = 0; op < n; op++) {
        if (s[op] == '1') {
            // Forward bubble: process the next unprocessed 1
            if (p1 < totalOnes) {
                // All remaining zeros to the right of this 1 will be swapped
                // The number of such zeros is: totalZeros - p0 - (zeros to the left of this 1)
                int zerosToRight = totalZeros - p0;
                // But we only count zeros to the right of this specific 1
                // The position of this 1 is pos1[p1]
                int zerosBeforeThis1 = 0;
                while (p0 < totalZeros && pos0[p0] < pos1[p1]) p0++;
                zerosToRight = totalZeros - p0;
                inv -= zerosToRight;
                if (inv < 0) inv = 0;
                p1++;
            }
        } else {
            // Reverse bubble: process the next unprocessed 0
            if (p0 < totalZeros) {
                // All remaining 1s to the left of this 0 will be swapped
                int onesToLeft = totalOnes - p1;
                // But we only count 1s to the left of this specific 0
                while (p1 < totalOnes && pos1[p1] < pos0[p0]) p1++;
                onesToLeft = totalOnes - p1;
                inv -= onesToLeft;
                if (inv < 0) inv = 0;
                p0++;
            }
        }
        cout << " " << inv;
    }
    cout << endl;
}

int main() {
    SpeedxKH;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}