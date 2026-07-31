#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 10;
    int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 5;
    cout << "Target: " << target << endl;

    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // two poiner two sum
    int l = 0;

    int r = n - 1;

    for (int i = 0; i < 10; i++)
    {
        if (arr[l] + arr[r] == target)
        {
            cout << "Pair found: " << arr[l] << ", " << arr[r] << endl;
            break;
        }
        else if (arr[l] + arr[r] < target)
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    // count pair with sum equal to target
    int count = 0;
    while (l < r)
    {
        if (arr[l] + arr[r] < target)
        {
            count += (r - l);
            l++;
        }
        else
        {
            r--;
        }
    }
    cout << "Count of pairs with sum < target: " << count << endl;

    // remove duplicates
    sort(arr, arr + n);
    int slow = 0;
    for (int fast = 1; fast < n; fast++)
    {
        if (arr[fast] != arr[slow])
        {
            slow++;
            arr[slow] = arr[fast];
        }
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i <= slow; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}