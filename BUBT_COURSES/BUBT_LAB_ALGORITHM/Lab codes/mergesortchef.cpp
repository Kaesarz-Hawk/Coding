#include <iostream>
#include <vector>
using namespace std;
void mergeSort(vector<int> &a)
{
    if (a.size() <= 1)
        return;
    int mid = a.size() / 2;
    vector<int> left(a.begin(), a.begin() + mid);
    vector<int> right(a.begin() + mid, a.end());
    mergeSort(left);
    mergeSort(right);
    int i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }
    while (i < left.size())
        a[k++] = left[i++];
    while (j < right.size())
        a[k++] = right[j++];
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(a);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}