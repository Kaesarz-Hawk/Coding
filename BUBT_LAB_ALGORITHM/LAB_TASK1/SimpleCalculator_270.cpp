#include <iostream>
using namespace std;

int main()
{
    int a, b;
    char op;

    cin >> a >> op >> b;

    if (op == '+')
    {
        cout << "Result: " << a + b;
    }
    else if (op == '-')
    {
        cout << "Result: " << a - b;
    }
    else if (op == '*')
    {
        cout << "Result: " << a * b;
    }
    else if (op == '/')
    {
        cout << "Result: " << a / b;
    }
    else
    {
        cout << "Invalid Operator";
    }

    return 0;
}