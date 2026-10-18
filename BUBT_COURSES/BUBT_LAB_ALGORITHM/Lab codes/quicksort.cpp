#include <iostream>
#include <vector>
using namespace std;
void quickSort(vector<int> &a, int l, int h)
{
    if (l >= h)
        return;
    int pivot = a[h];
    int i = l - 1;
    for (int j = l; j < h; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[h]);
    int p = i + 1;
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, h);
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}