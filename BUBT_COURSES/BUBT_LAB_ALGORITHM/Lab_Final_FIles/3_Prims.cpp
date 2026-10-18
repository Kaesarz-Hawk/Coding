#include <iostream>
using namespace std;

const int MAX = 100;
const int INF = 99999999;

// Undirected weighted adjacency matrix input
void inputEdgesToAdjMatrix(int adj[MAX][MAX], int n, int e)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = (i == j) ? 0 : INF;

    cout << "Enter edges (Source Destination Weight):\n";

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        if (u >= 1 && u <= n && v >= 1 && v <= n &&
            u != v && adj[u - 1][v - 1] == INF)
        {
            adj[u - 1][v - 1] = w;
            adj[v - 1][u - 1] = w; // undirected: MST needs both directions
        }
        else
        {
            cout << "Invalid edge. Try again.\n";
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
        {
            if (adj[i][j] == INF)
                cout << "INF ";
            else
                cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

// Prim's Algorithm - builds MST starting from a given node
void primMST(int adj[MAX][MAX], int n, int startNode)
{
    int key[MAX];     // minimum edge weight to connect node into MST
    int parent[MAX];  // stores MST tree structure (which node connects to which)
    bool inMST[MAX];  // true if node already included in MST

    for (int i = 0; i < n; i++)
    {
        key[i] = INF;
        inMST[i] = false;
        parent[i] = -1;
    }

    key[startNode] = 0; // start node has 0 cost to "connect" to itself

    for (int count = 0; count < n; count++)
    {
        // pick the node with minimum key value among nodes not yet in MST
        int u = -1;
        int minVal = INF;

        for (int i = 0; i < n; i++)
        {
            if (!inMST[i] && key[i] < minVal)
            {
                minVal = key[i];
                u = i;
            }
        }

        if (u == -1)
            break; // remaining nodes are unreachable (disconnected graph)

        inMST[u] = true;

        // update key values of adjacent nodes
        for (int v = 0; v < n; v++)
        {
            if (adj[u][v] != INF && !inMST[v] && adj[u][v] < key[v])
            {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }

    // print result
    cout << "\nEdge \tWeight\n";
    int totalWeight = 0;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] != -1)
        {
            cout << parent[i] + 1 << " - " << i + 1 << "\t" << key[i] << "\n";
            totalWeight += key[i];
        }
    }

    // check for disconnected nodes (couldn't be reached)
    for (int i = 0; i < n; i++)
    {
        if (!inMST[i])
        {
            cout << "Node " << i + 1 << " is unreachable, graph is disconnected.\n";
        }
    }

    cout << "\nTotal MST Weight = " << totalWeight << endl;
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
    while (e < 0 || e > n * (n - 1) / 2)
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

    primMST(adj, n, start - 1);

    return 0;
}
