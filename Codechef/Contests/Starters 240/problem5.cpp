#include <bits/stdc++.h>
using namespace std;

#define SpeedxKH                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    SpeedxKH;

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        
        vector<int> A(n);
        map<int, int> freq;
        int max_freq = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
            freq[A[i]]++;
            max_freq = max(max_freq, freq[A[i]]);
        }

        int ans = n - max_freq + 1;
        cout << ans << "\n";
    }

    return 0;
}