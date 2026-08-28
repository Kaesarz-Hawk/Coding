#include <iostream>
using namespace std;

const int MAX = 100;
int visited[MAX];

// Manual Queue class (no STL), same as taught in class
class Queue
{
    int arr[MAX];
    int front, rear;

public:
    Queue()
    {
        front = rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % MAX == front;
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % MAX;
        arr[rear] = val;
    }

    int dequeue()
    {
        if (isEmpty())
            return -1;
        int val = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
        return val;
    }
};

// BFS from a single starting node
void BFS(int adj[MAX][MAX], int n, int SN)
{
    Queue q;
    q.enqueue(SN);
    visited[SN] = 1;

    while (!q.isEmpty())
    {
        int cur = q.dequeue();
        cout << cur + 1 << " ";

        for (int i = 0; i < n; i++)
        {
            if (adj[cur][i] == 1 && visited[i] != 1)
            {
                q.enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

void inputEdgesToAdjMatrix(int adj[MAX][MAX], int n, int e)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    cout << "Enter edges (source destination):\n";

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        if (u >= 1 && u <= n && v >= 1 && v <= n &&
            u != v && adj[u - 1][v - 1] == 0)
        {
            adj[u - 1][v - 1] = 1;
            // If graph is undirected, also uncomment the line below:
            // adj[v - 1][u - 1] = 1;
        }
        else
        {
            cout << "Invalid edge\n";
            i--;
        }
    }
}

void printAdjMatrix(int adj[MAX][MAX], int n)
{
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n, e;
    int adj[MAX][MAX];

    cout << "Enter number of nodes: ";
    cin >> n;
    while (n <= 0 || n > MAX)
    {
        cout << "Invalid input, enter again: ";
        cin >> n;
    }

    cout << "Enter number of edges: ";
    cin >> e;
    while (e < 0 || e > n * (n - 1))
    {
        cout << "Invalid input, enter again: ";
        cin >> e;
    }

    inputEdgesToAdjMatrix(adj, n, e);
    printAdjMatrix(adj, n);

    int start;
    cout << "\nEnter starting node: ";
    cin >> start;
    while (start < 1 || start > n)
    {
        cout << "Invalid input, enter again: ";
        cin >> start;
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "\nBFS Traversal: ";
    BFS(adj, n, start - 1);

    // Handle disconnected components
    for (int i = 0; i < n; i++)
    {
        if (visited[i] != 1)
        {
            cout << "\n(node " << i + 1 << " was in a disconnected part, starting new BFS) ";
            BFS(adj, n, i);
        }
    }

    cout << endl;
    return 0;
}
