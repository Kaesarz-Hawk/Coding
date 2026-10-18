#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int original = n;
    int reverse = 0;

    while (n > 0)
    {
        int digit = n % 10;
        reverse = reverse * 10 + digit;
        n /= 10;
    }

    if (original == reverse)
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }

    return 0;
}