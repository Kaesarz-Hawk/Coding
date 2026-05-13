#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int temp = a;
    a = b;
    b = temp;

    cout << "a = " << a << endl;
    cout << "b = " << b;

    return 0;
}