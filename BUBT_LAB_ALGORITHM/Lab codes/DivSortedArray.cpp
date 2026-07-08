

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[105];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Step 1: Selection Sort (Ascending)
    for (int i = 0; i < n - 1; i++) {
        int mn = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[mn])
                mn = j;
        }
        swap(a[i], a[mn]);
    }

    // Step 2: Remove K-th element (1-based)
    int k;
    cin >> k;
    for (int i = k - 1; i < n - 1; i++)
        a[i] = a[i + 1];
    n--;

    // Step 3: Search for X
    int x;
    cin >> x;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            cout << "Found" << endl;
            cout << "Position = " << i + 1 << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Not Found" << endl;

    // Step 4: Print final array
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
