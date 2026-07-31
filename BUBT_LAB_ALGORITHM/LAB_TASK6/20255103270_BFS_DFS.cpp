#include <iostream>
using namespace std;

const int MAX = 100; // max nodes allowed

int visited[MAX];     // global visited array, shared across BFS/DFS calls
int startTime[MAX];   // start time for each node (DFS)
int finishTime[MAX];  // finish time for each node (DFS)
int time_counter = 0; // timer used in DFS

// Queue class for BFS
class Queue
{
    int arr[MAX];    // holds queue elements
    int front, rear; // front and rear index

public:
    Queue()
    {
        front = rear = -1; // empty queue at start
    }

    bool isEmpty()
    {
        return front == -1; // queue empty if front is -1
    }

    bool isFull()
    {
        return (rear + 1) % MAX == front; // circular full check
    }

    void enqueue(int val)
    {
        if (isFull()) // can't add if full
        {
            cout << "Queue is full\n";
            return;
        }

        if (isEmpty()) // first element
            front = rear = 0;
        else
            rear = (rear + 1) % MAX; // move rear forward

        arr[rear] = val; // insert value
    }

    int dequeue()
    {
        if (isEmpty()) // nothing to remove
            return -1;

        int val = arr[front]; // value to return

        if (front == rear) // only one element was left
            front = rear = -1;
        else
            front = (front + 1) % MAX; // move front forward

        return val;
    }
};

// Stack class for DFS
class Stack
{
    int arr[MAX]; // holds stack elements
    int top;      // index of top element

public:
    Stack()
    {
        top = -1; // empty stack at start
    }

    bool isEmpty()
    {
        return top == -1; // stack empty if top is -1
    }

    bool isFull()
    {
        return top == MAX - 1; // full when top hits last index
    }

    void push(int val)
    {
        if (isFull()) // can't add if full
        {
            cout << "Stack is full\n";
            return;
        }

        arr[++top] = val; // move top up, then insert
    }

    int pop()
    {
        if (isEmpty()) // nothing to remove
            return -1;

        return arr[top--]; // return top value, then move top down
    }

    int peek()
    {
        if (isEmpty()) // nothing on top
            return -1;

        return arr[top]; // just look at top value
    }
};

// BFS from a single starting node (SN), same steps as taught in class
void BFS(int adj[MAX][MAX], int n, int SN)
{
    Queue q; // queue for BFS

    q.enqueue(SN);   // put start node in queue
    visited[SN] = 1; // mark it visited

    while (!q.isEmpty()) // keep going till queue is empty
    {
        int cur = q.dequeue(); // take front node out

        cout << cur + 1 << " "; // print node (1-based)

        for (int i = 0; i < n; i++) // check every possible neighbour
        {
            if (adj[cur][i] == 1 && visited[i] != 1) // edge exists and not visited
            {
                q.enqueue(i);   // add neighbour to queue
                visited[i] = 1; // mark visited
            }
        }
    }
}

// DFS from a single starting node (SN), iterative using stack
// also records start time and finish time for each node
void DFS(int adj[MAX][MAX], int n, int SN)
{
    int nextChild[MAX] = {0}; // next neighbour to check for each node

    Stack st; // stack for DFS

    st.push(SN);                    // push starting node
    visited[SN] = 1;                // mark visited
    startTime[SN] = ++time_counter; // record start time
    cout << SN + 1 << " ";          // print node (1-based)
    nextChild[SN] = 0;              // begin checking from neighbour 0

    while (!st.isEmpty())
    {
        int cur = st.peek(); // look at node on top without removing
        bool found = false;  // did we find a new node to go into

        while (nextChild[cur] < n) // check remaining neighbours of cur
        {
            int next = nextChild[cur]; // neighbour to check
            nextChild[cur]++;          // move pointer so we don't recheck this one

            if (adj[cur][next] == 1 && visited[next] != 1) // valid unvisited neighbour
            {
                st.push(next);                    // go deeper into this neighbour
                visited[next] = 1;                // mark visited
                startTime[next] = ++time_counter; // record start time
                cout << next + 1 << " ";          // print node (1-based)
                nextChild[next] = 0;              // reset neighbour pointer for new node
                found = true;                     // we moved to a new node
                break;                            // stop checking, go back to while loop with new top
            }
        }

        if (!found) // no more unvisited neighbours left for cur
        {
            st.pop();                         // remove it from stack, it's fully done
            finishTime[cur] = ++time_counter; // record finish time
        }
    }
}

// takes edges from user and fills adjacency matrix
void inputEdgesToAdjMatrix(int adj[MAX][MAX], int n, int e)
{
    // Initialize matrix with 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    cout << "Enter edges (source destination):\n";

    for (int i = 0; i < e; i++)
    {
        int u, v;      // stores one edge (source, destination)
        cin >> u >> v; // read one edge

        // check nodes are in range, not same node, and edge not already there
        if (u >= 1 && u <= n &&
            v >= 1 && v <= n &&
            u != v &&
            adj[u - 1][v - 1] == 0)
        {
            adj[u - 1][v - 1] = 1; // mark edge in matrix
        }
        else
        {
            cout << "Invalid edge\n";
            i--; // ask for same edge number again
        }
    }
}

// prints the adjacency matrix
void printAdjMatrix(int adj[MAX][MAX], int n)
{
    cout << "\nAdjacency Matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << adj[i][j] << " "; // print each cell

        cout << endl; // new row
    }
}

int main()
{
    int n, e;          // number of nodes and number of edges
    int adj[MAX][MAX]; // adjacency matrix for the graph

    cout << "Enter number of nodes: ";
    cin >> n;

    while (n <= 0 || n > MAX) // keep asking until valid
    {
        cout << "Invalid input, enter again: ";
        cin >> n;
    }

    cout << "Enter number of edges: ";
    cin >> e;

    while (e < 0 || e > n * (n - 1)) // max possible edges without self loops
    {
        cout << "Invalid input, enter again: ";
        cin >> e;
    }

    inputEdgesToAdjMatrix(adj, n, e); // build the matrix

    printAdjMatrix(adj, n); // show matrix to user

    int start; // node the user wants to start traversal from

    cout << "Enter starting node: ";
    cin >> start;

    while (start < 1 || start > n) // keep asking until valid
    {
        cout << "Invalid input, enter again: ";
        cin >> start;
    }

    // ---- BFS ----
    for (int i = 0; i < n; i++) // reset visited before BFS
        visited[i] = 0;

    cout << "\nBFS Traversal: ";
    BFS(adj, n, start - 1); // BFS from the given start node

    // this loop covers disconnected nodes, same as taught in class:
    // if any node is still not visited after the first BFS call,
    // it means it belongs to a separate component, so we call
    // BFS again starting from that node
    for (int i = 0; i < n; i++)
    {
        if (visited[i] != 1)
        {
            cout << "\n(node " << i + 1 << " was in a disconnected part, starting new BFS) ";
            BFS(adj, n, i);
        }
    }

    cout << endl;

    // ---- DFS ----
    for (int i = 0; i < n; i++) // reset visited before DFS
        visited[i] = 0;
    time_counter = 0; // reset timer

    cout << "\nDFS Traversal: ";
    DFS(adj, n, start - 1); // DFS from the given start node

    // same disconnected handling for DFS
    for (int i = 0; i < n; i++)
    {
        if (visited[i] != 1)
        {
            cout << "\n(node " << i + 1 << " was in a disconnected part, starting new DFS) ";
            DFS(adj, n, i);
        }
    }

    cout << endl;

    // print start and finish time table for DFS
    cout << "\nNode\tStart\tFinish\n";
    for (int i = 0; i < n; i++)
        cout << i + 1 << "\t" << startTime[i] << "\t" << finishTime[i] << endl;

    return 0;
}

/*
Done by: Kawsar_270!
*/

/*
5
5
1 2
1 3
2 4
3 5
4 5
1
*/
