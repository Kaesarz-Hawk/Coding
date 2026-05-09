#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
   
    int t;
    cin >> t;
    
    while (t--) {
      
        int N;
        cin >> N;

        vector<int> A(N);
        
        for (int i = 0; i < N; i++) cin >> A[i];
        
        sort(A.begin(), A.end());
        set<int> res;
        
        do {
            int X = 0;
            for (int a : A) {
                X = (X < a) ? -1 : (X == a) ? 0 : 1;
            }
            res.insert(X);
        } while (next_permutation(A.begin(), A.end()));
        
        for (int x : res) cout << x << " ";
      
        cout << "\n";
    }
}