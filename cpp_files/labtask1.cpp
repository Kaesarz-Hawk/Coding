#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBegin(int val)
{
    Node* newNode = new Node{val, head};
    head = newNode;
}

// Insert at end
void insertEnd(int val)
{
    Node* newNode = new Node{val, NULL};

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert at position
void insertAt(int val, int pos)
{
    if (pos == 1)
    {
        insertBegin(val);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Position out of range" << endl;
        return;
    }

    Node* newNode = new Node{val, temp->next};
    temp->next = newNode;
}

// Delete at beginning
void deleteBegin()
{
    if (head == NULL) return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete at end
void deleteEnd()
{
    if (head == NULL) return;

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

// Delete at position
void deleteAt(int pos)
{
    if (pos == 1)
    {
        deleteBegin();
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
    {
        cout << "Position out of range" << endl;
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

// Display
void display()
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    insertBegin(10);
    insertEnd(20);
    insertAt(15, 2);

    cout << "After Insert: ";
    display();

    deleteAt(2);

    cout << "After Delete: ";
    display();

    return 0;
}