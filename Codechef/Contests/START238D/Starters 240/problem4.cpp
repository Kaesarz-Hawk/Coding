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

        string A, B;
        cin >> A >> B;

        vector<int> positionA, positionB;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == '1')
             positionA.push_back(i);
            if (B[i] == '1')
             positionB.push_back(i);
        }

        if (positionA.size() != positionB.size())
        {
            cout << -1 << "\n";
            continue;
        }

        int total_operations = 0;

        for (size_t i = 0; i < positionA.size(); i++)
        {
            if (positionA[i] != positionB[i])
            {
                total_operations++;
                positionA[i] = positionB[i]; 
            }
        }

        cout << total_operations << "\n";
    }

    return 0;
}