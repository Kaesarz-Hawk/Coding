#include <iostream>
using namespace std;

int partition(int A[], int l, int h)
{
    int i = l;
    int j = h;
    int pivot = A[l];

    while (i < j)
    {
        while (i <= h && A[i] <= pivot)
            i++;
        while (A[j] > pivot)
            j--;
        if (i < j)
            swap(A[i], A[j]);
    }
    swap(A[l], A[j]);
    return j;
}

void quickSort(int A[], int l, int h)
{
    if (l < h)
    {
        int pivot = partition(A, l, h);
        quickSort(A, l, pivot);
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