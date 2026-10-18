#include <iostream>
using namespace std;

const int MAX = 100;
const int MAXE = MAX * MAX;

int parent[MAX]; // manual Union-Find structure

// find the "group leader" of a node (with path compression)
int findParent(int node)
{
    if (parent[node] == node)
        return node;
    parent[node] = findParent(parent[node]); // path compression
    return parent[node];
}

// join two groups together
void unionNodes(int a, int b)
{
    int pa = findParent(a);
    int pb = findParent(b);
    if (pa != pb)
        parent[pa] = pb;
}

struct Edge
{
    int u, v, weight;
};

// simple manual sort (ascending by weight), matching class-taught style
void sortEdges(Edge edges[], int e)
{
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void inputEdges(Edge edges[], int n, int e)
{
    cout << "Enter edges (Source Destination Weight):\n";

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

// Kruskal's Algorithm - builds MST by picking smallest edges that don't form a cycle
void kruskalMST(Edge edges[], int n, int e)
{
    sortEdges(edges, e);

    for (int i = 0; i < n; i++)
        parent[i] = i; // every node is its own group leader initially

    int edgeCount = 0;
    int totalWeight = 0;

    cout << "\nEdge \tWeight\n";

    for (int i = 0; i < e && edgeCount < n - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        if (findParent(u) != findParent(v)) // adding this edge won't form a cycle
        {
            unionNodes(u, v);
            cout << u + 1 << " - " << v + 1 << "\t" << edges[i].weight << "\n";
            totalWeight += edges[i].weight;
            edgeCount++;
        }
    }

    if (edgeCount < n - 1)
    {
        cout << "\nGraph is disconnected. MST could not include all nodes.\n";
        cout << "Edges used: " << edgeCount << " out of required " << n - 1 << "\n";
    }

    cout << "\nTotal MST Weight = " << totalWeight << endl;
}

int main()
{
    int n, e;
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
    while (e < 0 || e > n * (n - 1) / 2)
    {
        cout << "Invalid input, enter again: ";
        cin >> e;
    }

    inputEdges(edges, n, e);

    kruskalMST(edges, n, e);

    return 0;
}
