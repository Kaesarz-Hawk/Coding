#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int binarySearch(int arr[], int low, int high, int target)
{
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == target) return mid;
    if (target < arr[mid]) return binarySearch(arr, low, mid - 1, target);
    return binarySearch(arr, mid + 1, high, target);
}

void hanoi(int n, char source, char destination, char aux)
{
    if (n == 1)
    {
        cout << "Move disk 1: " << source << " -> " << destination << endl;
        return;
    }
    hanoi(n - 1, source, aux, destination);
    cout << "Move disk " << n << ": " << source << " -> " << destination << endl;
    hanoi(n - 1, aux, destination, source);
}

int main()
{
    cout << "Factorial(5) = " << factorial(5) << endl;

    cout << "Fibonacci: ";
    for (int i = 0; i < 8; i++) cout << fibonacci(i) << " ";
    cout << endl;

    int arr[] = {10, 20, 30, 40, 50};
    cout << "Binary Search(30) = index " << binarySearch(arr, 0, 4, 30) << endl;

    cout << "\nTower of Hanoi (3 disks):" << endl;
    hanoi(3, 'A', 'C', 'B');

    return 0;
}