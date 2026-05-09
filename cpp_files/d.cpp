#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        if (N == 2) {
            cout << "01" << endl;
            continue;
        }

        cout << '0';
        for (int i = 0; i < N - 2; i++) {
            cout << '1';
        }
        cout << '0' << endl;
    }

    return 0;
}
