#include <iostream>
using namespace std;

void merge(int A[], int l, int m, int h)
{
    int n1 = m - l + 1;
    int n2 = h - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int A[], int l, int h)
{
    if (l < h)
    {
        int m = (l + h) / 2;
        mergesort(A, l, m);
        mergesort(A, m + 1, h);
        merge(A, l, m, h);
    }
}

int main()
{
    int n;
    cout << "Size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter your array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (n > 0)
    {
        mergesort(arr, 0, n - 1);
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
