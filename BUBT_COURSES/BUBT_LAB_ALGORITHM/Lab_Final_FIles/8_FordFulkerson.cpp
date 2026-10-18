#include <iostream>
using namespace std;

const int MAX = 100;
const int INF = 99999999;

int capacity_[MAX][MAX]; // residual capacity graph
int parent[MAX];

void inputEdgesToAdjMatrix(int n, int e)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            capacity_[i][j] = 0;

    cout << "Enter edges (Source Destination Capacity):\n";

    for (int i = 0; i < e; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;

        if (u >= 1 && u <= n && v >= 1 && v <= n && u != v && c > 0)
        {
            capacity_[u - 1][v - 1] += c; // += in case of parallel edges
        }
        else
        {
            cout << "Invalid edge. Try again.\n";
            i--;
        }
    }
}

// Manual BFS to find an augmenting path in the residual graph
// Uses a simple array-based queue, same manual style as taught in class
bool bfsFindPath(int n, int source, int sink)
{
    bool visited[MAX] = {false};
    int queueArr[MAX];
    int qFront = 0, qRear = 0;

    queueArr[qRear++] = source;
    visited[source] = true;
    parent[source] = -1;

    while (qFront < qRear)
    {
        int u = queueArr[qFront++];

        for (int v = 0; v < n; v++)
        {
            // an edge exists in the residual graph if capacity remaining > 0
            if (!visited[v] && capacity_[u][v] > 0)
            {
                queueArr[qRear++] = v;
                visited[v] = true;
                parent[v] = u;

                if (v == sink)
                    return true; // reached sink, augmenting path found
            }
        }
    }

    return false; // no augmenting path exists
}

// Ford-Fulkerson Algorithm (implemented with BFS = Edmonds-Karp variant)
void fordFulkerson(int n, int source, int sink)
{
    int maxFlow = 0;
    int pathNumber = 1;

    while (bfsFindPath(n, source, sink))
    {
        // find the bottleneck capacity along this augmenting path
        int pathFlow = INF;
        int v = sink;
        while (v != source)
        {
            int u = parent[v];
            if (capacity_[u][v] < pathFlow)
                pathFlow = capacity_[u][v];
            v = u;
        }

        // print the augmenting path found
        cout << "\nAugmenting Path " << pathNumber << ": ";
        int pathNodes[MAX];
        int len = 0;
        v = sink;
        while (v != -1)
        {
            pathNodes[len++] = v;
            v = parent[v];
        }
        for (int i = len - 1; i >= 0; i--)
        {
            cout << pathNodes[i] + 1;
            if (i != 0)
                cout << " -> ";
        }
        cout << "  (Bottleneck Capacity = " << pathFlow << ")\n";

        // update residual capacities along the path
        v = sink;
        while (v != source)
        {
            int u = parent[v];
            capacity_[u][v] -= pathFlow; // forward edge: reduce remaining capacity
            capacity_[v][u] += pathFlow; // backward edge: allow flow to be "undone"
            v = u;
        }

        maxFlow += pathFlow;
        pathNumber++;
    }

    cout << "\nMaximum Flow = " << maxFlow << endl;
}

int main()
{
    int n, e;

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

    inputEdgesToAdjMatrix(n, e);

    int source, sink;
    cout << "\nEnter Source node: ";
    cin >> source;
    while (source < 1 || source > n)
    {
        cout << "Invalid input, enter again: ";
        cin >> source;
    }

    cout << "Enter Sink node: ";
    cin >> sink;
    while (sink < 1 || sink > n || sink == source)
    {
        cout << "Invalid input, enter again: ";
        cin >> sink;
    }

    fordFulkerson(n, source - 1, sink - 1);

    return 0;
}
