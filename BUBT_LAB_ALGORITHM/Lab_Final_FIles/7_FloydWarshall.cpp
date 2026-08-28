#include <iostream>
using namespace std;

const int MAX = 100;
const int INF = 99999999;

void inputEdgesToAdjMatrix(int adj[MAX][MAX], int n, int e)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = (i == j) ? 0 : INF;

    cout << "Enter edges (Source Destination Weight):\n";
    cout << "(Negative weights are allowed, but no negative cycles)\n";

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        if (u >= 1 && u <= n && v >= 1 && v <= n && u != v)
        {
            adj[u - 1][v - 1] = w;
        }
        else
        {
            cout << "Invalid edge. Try again.\n";
            i--;
        }
    }
}

void printMatrix(int mat[MAX][MAX], int n, string label)
{
    cout << "\n" << label << ":\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] >= INF)
                cout << "INF\t";
            else
                cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

// Floyd-Warshall Algorithm - all pairs shortest path
// dist[][]  = shortest distance matrix (this is the "D" matrix from class notes)
// next[][]  = path reconstruction matrix (this is the "P" matrix from class notes)
void floydWarshall(int adj[MAX][MAX], int n)
{
    int dist[MAX][MAX];
    int next[MAX][MAX];

    // initialize dist = adjacency matrix, next[i][j] = j (direct path guess)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = adj[i][j];
            if (i != j && adj[i][j] != INF)
                next[i][j] = j;
            else
                next[i][j] = -1;
        }
    }

    // main triple loop: try every node k as an intermediate point
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k]; // update path: go through k
                }
            }
        }
    }

    // check for negative cycles: if any dist[i][i] < 0, a negative cycle exists
    bool hasNegativeCycle = false;
    for (int i = 0; i < n; i++)
    {
        if (dist[i][i] < 0)
        {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle)
    {
        cout << "\nGraph contains a negative weight cycle!\n";
        cout << "Shortest paths are not well-defined.\n";
        return;
    }

    printMatrix(dist, n, "Shortest Distance Matrix (D)");

    cout << "\nEnter a pair of nodes to see the shortest path between them.\n";
    cout << "Enter source and destination (1-indexed): ";
    int src, dest;
    cin >> src >> dest;

    if (src < 1 || src > n || dest < 1 || dest > n)
    {
        cout << "Invalid nodes.\n";
        return;
    }

    src--; dest--;

    if (dist[src][dest] >= INF)
    {
        cout << "No path exists between " << src + 1 << " and " << dest + 1 << ".\n";
        return;
    }

    cout << "Shortest distance = " << dist[src][dest] << "\n";
    cout << "Path: ";

    if (next[src][dest] == -1)
    {
        cout << "(no path)\n";
    }
    else
    {
        int at = src;
        cout << at + 1;
        while (at != dest)
        {
            at = next[at][dest];
            cout << " -> " << at + 1;
        }
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

    floydWarshall(adj, n);

    return 0;
}
