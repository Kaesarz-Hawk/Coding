// Author  : Kaesarz
// Date    : 16-09-2026
// Time    : 11:19

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
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    // matrix printing

    cout << "The matrix is:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // row
    cout << "Sum of the rows are : " << endl;

    for (int i = 0; i < 3; i++)
    {
        int sumrow = 0;
        for (int j = 0; j < 3; j++)
        {
            sumrow += matrix[i][j];
        }
        cout << i + 1 << " row : ";
        cout << sumrow << " " << endl;
    }

    cout << endl;

    // column
    cout << "Sum of the columns are : " << endl;

    for (int j = 0; j < 3; j++)
    {
        int sumcolumn = 0;
        for (int i = 0; i < 3; i++)
        {
            sumcolumn += matrix[i][j];
        }
        cout << j + 1 << " column : ";
        cout << sumcolumn << " " << endl;
    }
}

int main()
{
    SpeedxKH;

    // int t;
    // cin >> t;
    // while (t--) solve();

    // single test case
    solve();

    return 0;
}