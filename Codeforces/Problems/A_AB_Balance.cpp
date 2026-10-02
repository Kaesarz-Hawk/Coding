// Author  : Kaesarz
// Date    : 02-10-2026
// Time    : 15:58

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    string s;
    cin >> s;

    
    int freqAB = 0, freqBA = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'a' && s[i + 1] == 'b') {
            freqAB++;
        } else if (s[i] == 'b' && s[i + 1] == 'a') {
            freqBA++;
        }
    }

    bool equal = false;

    if (freqAB == freqBA) {
        equal = true;
    }

    if (equal) {
        cout << s << endl;
        return;
    }

    
    if(!equal) {
        
        for (int i = 0; i < s.size(); i++) {
            char originalChar = s[i];
            if (s[i] == 'a') {
                s[i] = 'b';
            } else if (s[i] == 'b') {
                s[i] = 'a';
            }

            
            freqAB = 0;
            freqBA = 0;
            for (int j = 0; j < s.size() - 1; j++) {
                if (s[j] == 'a' && s[j + 1] == 'b') {
                    freqAB++;
                } else if (s[j] == 'b' && s[j + 1] == 'a') {
                    freqBA++;
                }
            }

            if (freqAB == freqBA) {
                cout << s << endl;
                return;
            }

           
            s[i] = originalChar;

        }
    }

}

int main() {
    SpeedxKH;

    int t;
     cin >> t;
     while (t--) solve();

   
    return 0;
}