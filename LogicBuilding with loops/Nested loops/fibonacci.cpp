#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    // To print rows with increasing lengths (1, 2, 3...),
    // we simply iterate row by row.
    // Row i requires us to print the next 'i' numbers of the Fibonacci sequence.

    // We need two variables to track the sequence state.
    int a = 1;
    int b = 1;

    // Counter for total numbers generated globally
    int count = 0;

    cout << "Fibonacci Pattern:" << endl;

    for (int row = 1; row <= n; row++)
    {
        int limit = row; // Row size increases

        for (int i = 0; i < limit; i++)
        {
            if (count == 0)
            {
                cout << a;
                count++;
            }
            else if (count == 1)
            {
                // Second number in sequence is 'b' (which is also 1 initially)
                cout << " " << b;
                count++;

                // Now we must update a and b to generate the next numbers
                // Because for row 2, i=0 printed 'a'(1). i=1 printed 'b'(1).
                // Next number should be a+b = 2.
            }
            else if (count > 1)
            {
                int temp = a + b;
                a = b;
                b = temp;
                cout << " " << a;
                count++;
            }
        }
        cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}
