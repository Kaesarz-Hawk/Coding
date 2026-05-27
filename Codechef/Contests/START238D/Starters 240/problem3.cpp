#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
        for (int i = 0; i < n; i++)
            cin >> A[i];

        sort(A.begin(), A.end());

        bool comfortable = true;

        if (A[0] < A[1])
        {
            comfortable = false;
        }

        cout << (comfortable ? "YES" : "NO") << "\n";
    }

    return 0;
}