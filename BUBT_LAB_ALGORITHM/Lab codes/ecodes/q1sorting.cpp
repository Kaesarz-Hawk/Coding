#include <iostream>
#include <vector>
using namespace std;

/* void bubbleSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

void selectionSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        int mn = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[mn])
                mn = j;
        swap(a[i], a[mn]);
    }
}

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
*/
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

        // bubbleSort(a);
    // selectionSort(a);
    // mergeSort(a);
    // quickSort(a, 0, n - 1);

    int k;
    cin >> k;
    a.erase(a.begin() + k - 1);

    int x;
    cin >> x;

    bool found = false;
    for (int i = 0; i < (int)a.size(); i++)
    {
        if (a[i] == x)
        {
            cout << "Found" << endl;
            cout << "Position = " << i + 1 << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Not Found" << endl;

    for (int i = 0; i < (int)a.size(); i++)
    {
        cout << a[i];
        if (i < (int)a.size() - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}