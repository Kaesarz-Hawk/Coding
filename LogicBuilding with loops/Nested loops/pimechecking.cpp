#include <iostream>
using namespace std;

void solve() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    // Handle edge case where n is small
    if (n < 2) {
        cout << "No prime numbers less than or equal to " << n << endl;
        return;
    }

    cout << "Prime numbers up to " << n << ":" << endl;
    
    
    for (int i = 2; i <= n; i++) {
        bool isPrime = true; 
        
        
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = false; 
                break;           
            }
        }

       
        if (isPrime) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}
