#include <iostream>
using namespace std;

#define MAX 5

int queue_arr[MAX];
int front = -1;
int rear = -1;

void enqueue(int val)
{
    if (rear == MAX - 1)
    {
        cout << "Queue is full" << endl;
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue_arr[rear] = val;
    cout << "Enqueued: " << val << endl;
}

void dequeue()
{
    if (front == -1 or front > rear)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Dequeued: " << queue_arr[front] << endl;
    front++;
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void peek()
{
    if (front == -1 or front > rear)
        cout << "Queue is empty" << endl;
    else
        cout << "Front: " << queue_arr[front] << endl;
}

void display()
{
    if (front == -1 or front > rear)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = front; i <= rear; i++)
        cout << queue_arr[i] << " ";
    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    peek();
    display();
    dequeue();
    display();

    return 0;
}