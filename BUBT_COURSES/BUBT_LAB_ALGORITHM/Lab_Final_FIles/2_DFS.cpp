#include <iostream>
using namespace std;

const int MAX = 100;
int visited[MAX];
int startTime[MAX];
int finishTime[MAX];
int time_counter = 0;

// Manual Stack class (no STL), same as taught in class
class Stack
{
    int arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX - 1;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack is full\n";
            return;
        }
        arr[++top] = val;
    }

    int pop()
    {
        if (isEmpty())
            return -1;
        return arr[top--];
    }

    int peek()
    {
        if (isEmpty())
            return -1;
        return arr[top];
    }
};

// Iterative DFS using a stack, records start/finish time for each node
void DFS(int adj[MAX][MAX], int n, int SN)
{
    int nextChild[MAX] = {0};
    Stack st;

    st.push(SN);
    visited[SN] = 1;
    startTime[SN] = ++time_counter;
    cout << SN + 1 << " ";
    nextChild[SN] = 0;

    while (!st.isEmpty())
    {
        int cur = st.peek();
        bool found = false;

        while (nextChild[cur] < n)
        {
            int next = nextChild[cur];
            nextChild[cur]++;

            if (adj[cur][next] == 1 && visited[next] != 1)
            {
                st.push(next);
                visited[next] = 1;
                startTime[next] = ++time_counter;
                cout << next + 1 << " ";
                nextChild[next] = 0;
                found = true;
                break;
            }
        }

        if (!found)
        {
            st.pop();
            finishTime[cur] = ++time_counter;
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
    time_counter = 0;

    cout << "\nDFS Traversal: ";
    DFS(adj, n, start - 1);

    // Handle disconnected components
    for (int i = 0; i < n; i++)
    {
        if (visited[i] != 1)
        {
            cout << "\n(node " << i + 1 << " was in a disconnected part, starting new DFS) ";
            DFS(adj, n, i);
        }
    }

    cout << endl;

    cout << "\nNode\tStart\tFinish\n";
    for (int i = 0; i < n; i++)
        cout << i + 1 << "\t" << startTime[i] << "\t" << finishTime[i] << endl;

    return 0;
}
