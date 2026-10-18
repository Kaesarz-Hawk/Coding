#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;
const int INF = 99999999;

void inputEdgesToAdjMatrix(int adj[MAX][MAX], int n, int e)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                adj[i][j] = 0;
            else
                adj[i][j] = INF;
        }
    }

    cout << "Enter edges (Source Destination Weight):\n";

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        if (u >= 1 && u <= n && v >= 1 && v <= n &&
            u != v && adj[u - 1][v - 1] == INF)
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

void dijkstra(int adj[MAX][MAX], int n, int source)
{
    int D[MAX];
    bool V[MAX];

    for (int i = 0; i < n; i++)
    {
        D[i] = INF;
        V[i] = false;
    }

    D[source] = 0;

    while (true)
    {
        int min = INF;
        int SN = -1;

        // Find minimum distance unvisited node
        for (int i = 0; i < n; i++)
        {
            if (!V[i] && D[i] < min)
            {
                min = D[i];
                SN = i;
            }
        }

        if (SN == -1)
            break;

        V[SN] = true;

        // Update distances
        for (int i = 0; i < n; i++)
        {
            if (!V[i] &&
                adj[SN][i] != INF &&
                D[SN] + adj[SN][i] < D[i])
            {
                D[i] = D[SN] + adj[SN][i];
            }
        }
    }

    cout << "\nShortest Distance from Node " << source + 1 << ":\n";

    for (int i = 0; i < n; i++)
    {
        if (D[i] == INF)
            cout << source + 1 << " -> " << i + 1 << " = INF\n";
        else
            cout << source + 1 << " -> " << i + 1 << " = " << D[i] << endl;
    }
}

int main()
{
    int n, e;
    int adj[MAX][MAX];

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0 || n > MAX)
    {
        cout << "Invalid number of nodes.\n";
        return 0;
    }

    cout << "Enter number of edges: ";
    cin >> e;

    inputEdgesToAdjMatrix(adj, n, e);

    printAdjMatrix(adj, n);

    int source;
    cout << "\nEnter source node: ";
    cin >> source;

    dijkstra(adj, n, source - 1);

    return 0;
}