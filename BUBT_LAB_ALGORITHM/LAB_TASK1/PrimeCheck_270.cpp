#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    bool prime = true;

    if (n <= 1)
    {
        prime = false;
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                prime = false;
                break;
            }
        }
    }

    if (prime)
    {
        cout << "Prime";
    }
    else
    {
        cout << "Not Prime";
    }

    return 0;
}