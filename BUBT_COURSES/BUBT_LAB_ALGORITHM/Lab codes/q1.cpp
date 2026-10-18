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
            if (a[j] < a[mn])
                mn = j;
        swap(a[i], a[mn]);
    }
    cout << "Sorted Array:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n\n";
    int k;
    cin >> k;
    for (int i = k - 1; i < n - 1; i++)
        a[i] = a[i + 1];
    n--;
    cout << "Updated Array:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n\n";
    int x;
    cin >> x;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            cout << "Found\n";
            cout << "Position = " << i + 1;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Not Found";
    return 0;
}