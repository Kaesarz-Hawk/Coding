#include <iostream>
using namespace std;

const int MAX = 100;
const int INF = 99999999;

struct Edge
{
    int u, v, weight;
};

void inputEdges(Edge edges[], int n, int e)
{
    cout << "Enter edges (Source Destination Weight):\n";
    cout << "(Negative weights are allowed for this algorithm)\n";

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        if (u >= 1 && u <= n && v >= 1 && v <= n && u != v)
        {
            edges[i].u = u - 1;
            edges[i].v = v - 1;
            edges[i].weight = w;
        }
        else
        {
            cout << "Invalid edge. Try again.\n";
            i--;
        }
    }
}

// Bellman-Ford Algorithm - relaxes all edges (n-1) times
void bellmanFord(Edge edges[], int n, int e, int source)
{
    int dist[MAX];

    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[source] = 0;

    // relax all edges (n-1) times, matching the iteration-table method from class
    for (int iteration = 1; iteration <= n - 1; iteration++)
    {
        bool updatedThisRound = false;
        cout << "\n--- Iteration " << iteration << " ---\n";

        for (int i = 0; i < e; i++)
        {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].weight;

            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                cout << "Edge " << u + 1 << " -> " << v + 1
                     << " updated. New dist[" << v + 1 << "] = " << dist[v] << "\n";
                updatedThisRound = true;
            }
        }

        if (!updatedThisRound)
        {
            cout << "No updates this round. Distances have stabilized early.\n";
            break;
        }
    }

    // one extra pass to detect negative weight cycles
    bool hasNegativeCycle = false;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (dist[u] != INF && dist[u] + w < dist[v])
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

    cout << "\nShortest Distance from Node " << source + 1 << ":\n";
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            cout << source + 1 << " -> " << i + 1 << " = INF\n";
        else
            cout << source + 1 << " -> " << i + 1 << " = " << dist[i] << "\n";
    }
}

int main()
{
    int n, e;
    const int MAXE = MAX * MAX;
    Edge edges[MAXE];

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

    inputEdges(edges, n, e);

    int source;
    cout << "\nEnter source node: ";
    cin >> source;
    while (source < 1 || source > n)
    {
        cout << "Invalid input, enter again: ";
        cin >> source;
    }

    bellmanFord(edges, n, e, source - 1);

    return 0;
}
