#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin, s);

        for (int i = 0; i < s.size(); ) {

            if (s[i] == ' ') { i++; continue; }

            int j = i;
            bool allUpper = true;

            while (j < s.size() && s[j] != ' ') {
                if (islower(s[j])) allUpper = false;
                j++;
            }

            if (!allUpper) {
                s[i] = toupper(s[i]);
                for (int k = i + 1; k < j; k++)
                    s[k] = tolower(s[k]);
            }

            i = j;
        }

        cout << s << "\n";
    }
}