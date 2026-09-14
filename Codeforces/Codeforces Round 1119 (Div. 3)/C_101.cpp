// Author  : Kaesarz
// Date    : 05-09-2026
// Time    : 20:56

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ones;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            ones.push_back(i);
    }

    if (ones.empty())
    {
        int first = -1, last = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == -1)
            {
                if (first == -1)
                    first = i;
                last = i;
            }
        }
        if (first != -1)
        {
            a[first] = 1;
            if (last != first)
                a[last] = 1;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == -1)
                    a[i] = 0;
            }
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << '\n';
        return;
    }

    int bestLeft = -1, bestRight = -1;
    int bestLength = 0;

    auto consider = [&](int leftBoundary, int rightBoundary)
    {
        int l = leftBoundary + 1;
        int r = rightBoundary - 1;
        int leftNonZero = -1;
        int rightNonZero = -1;

        if (leftBoundary != -1 && a[leftBoundary] == 1)
        {
            leftNonZero = leftBoundary;
        }

        for (int i = l; i <= r; i++)
        {
            if (a[i] != 0)
            {
                if (leftNonZero == -1)
                    leftNonZero = i;
                rightNonZero = i;
            }
        }

        if (rightBoundary != n && a[rightBoundary] == 1)
        {
            if (leftNonZero == -1)
                leftNonZero = rightBoundary;
            rightNonZero = rightBoundary;
        }

        if (leftNonZero != -1 && rightNonZero != -1)
        {
            int len = rightNonZero - leftNonZero + 1;
            if (len > bestLength)
            {
                bestLength = len;
                bestLeft = leftNonZero;
                bestRight = rightNonZero;
            }
        }
    };

    consider(-1, ones[0]);

    for (int i = 0; i + 1 < (int)ones.size(); i++)
    {
        consider(ones[i], ones[i + 1]);
    }

    consider(ones.back(), n);

    if (bestLeft != -1 && a[bestLeft] == -1)
        a[bestLeft] = 1;
    if (bestRight != -1 && a[bestRight] == -1)
        a[bestRight] = 1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
            a[i] = 0;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << '\n';
}

int main()
{
    SpeedxKH;

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}