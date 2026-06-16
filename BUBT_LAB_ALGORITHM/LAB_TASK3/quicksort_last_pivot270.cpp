#include <iostream>
using namespace std;

int partition(int A[], int l, int h)
{
    int pivot = A[h];
    int i = l - 1;

    for (int j = l; j < h; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[h]);
    return i + 1;
}

void quickSort(int A[], int l, int h)
{
    if (l < h)
    {
        int pivot = partition(A, l, h);
        quickSort(A, l, pivot - 1);
        quickSort(A, pivot + 1, h);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n > 0)
        quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}