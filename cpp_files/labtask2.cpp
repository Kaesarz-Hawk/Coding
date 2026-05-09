#include <iostream>
using namespace std;

#define MAX_STACK 5

int stack_arr[MAX_STACK];
int top = -1;

// Push
void push()
{
    int x;
    if (top == MAX_STACK - 1)
    {
        cout << "Overflow" << endl;
    }
    else
    {
        cout << "Enter value: ";
        cin >> x;

        top++;
        stack_arr[top] = x;
    }
}

// Pop
void pop()
{
    if (top == -1)
    {
        cout << "Underflow" << endl;
    }
    else
    {
        cout << "Deleted: " << stack_arr[top] << endl;
        top--;
    }
}

// Peek
void peek()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Top element: " << stack_arr[top] << endl;
    }
}

// Display
void display()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            cout << stack_arr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int choice;

    while (1)
    {
        cout << endl;
        cout << "1.Push 2.Pop 3.Peek 4.Display 5.Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}