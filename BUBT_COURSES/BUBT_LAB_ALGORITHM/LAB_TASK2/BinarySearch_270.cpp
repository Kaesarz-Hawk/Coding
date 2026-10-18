#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cin >> key;

    int low = 0, high = n - 1;
    int iterations = 0;
    bool found = false;

    while (low <= high)
    {
        iterations++;
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            cout << "Found at index " << mid;
            found = true;
            break;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (!found)
        cout << "Not Found";
    cout << endl << "Iterations: " << iterations;
    return 0;
}
