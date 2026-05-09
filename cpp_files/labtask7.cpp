#include <iostream>
using namespace std;

#define MAX 10

int heap[MAX];
int heapSize = 0;

void heapifyUp(int i)
{
    int parent = (i - 1) / 2;
    if (i > 0 && heap[i] > heap[parent])
    {
        swap(heap[i], heap[parent]);
        heapifyUp(parent);
    }
}

void heapifyDown(int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < heapSize && heap[left] > heap[largest])
        largest = left;
    if (right < heapSize && heap[right] > heap[largest])
        largest = right;

    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        heapifyDown(largest);
    }
}

void display()
{
    for (int i = 0; i < heapSize; i++)
        cout << heap[i] << " ";
    cout << endl;
}

void insert(int val)
{
    heap[heapSize] = val;
    heapSize++;
    heapifyUp(heapSize - 1);
    cout << "Inserted " << val << ": ";
    display();
}

void deleteRoot()
{
    if (heapSize == 0)
    {
        cout << "Heap is empty." << endl;
        return;
    }

    cout << "Deleted root: " << heap[0] << endl;
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(0);
    cout << "After deletion: ";
    display();
}

int main()
{
    insert(10);
    insert(20);
    insert(15);
    insert(30);
    insert(40);

    cout << endl;
    deleteRoot();

    return 0;
}