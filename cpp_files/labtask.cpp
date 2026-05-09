#include <iostream>
using namespace std;
int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a[10], n, x;
    int low=0, high, mid;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    cin >> x;
    high = n-1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == x) {
            cout << "Found at index " << mid;
            return 0;
        }
        else if (a[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "Not Found";
    return 0;
}