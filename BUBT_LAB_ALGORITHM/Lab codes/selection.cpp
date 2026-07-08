#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        int mn = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[mn])
                mn = j;
        }
        swap(a[i], a[mn]);
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}