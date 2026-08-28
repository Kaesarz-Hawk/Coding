#include <iostream>
using namespace std;

const int N = 8;
char nodeName[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int adj[N][N] = {};
bool visited[N] = {};
bool active[N] = {};
int parentNode[N];
bool cycleFound = false;
bool cycleMarked[N] = {};

// Each undirected edge {u,v} would otherwise be re-discovered as a
// "back edge" from BOTH endpoints (once when the deeper node looks
// back up, once when the shallower node's own loop reaches it later).
// reportedEdge[u][v] stops the second, duplicate report.
bool reportedEdge[N][N] = {};

int cycleCount = 0;

void markCycle(int u, int v)
{
    // Back edge u -> v : v is an ancestor of u in the DFS tree.
    cycleFound = true;
    cycleCount++;
    cycleMarked[u] = true;
    cycleMarked[v] = true;

    cout << "    Cycle #" << cycleCount << ": " << nodeName[v];
    // Walk from u up to v along parent pointers to print the full cycle.
    int x = u;
    int path[N], len = 0;
    while (x != v && x != -1)
    {
        path[len++] = x;
        cycleMarked[x] = true;
        x = parentNode[x];
    }
    for (int i = len - 1; i >= 0; --i)
        cout << " - " << nodeName[path[i]];
    cout << " - " << nodeName[v] << '\n';
}

void dfs(int u)
{
    visited[u] = true;
    active[u] = true;

    cout << "Enter " << nodeName[u] << " | DFS path: ";
    for (int i = 0; i < N; ++i)
        if (active[i])
            cout << nodeName[i] << ' ';
    cout << '\n';

    for (int v = 0; v < N; ++v)
    {
        if (!adj[u][v])
            continue;

        if (!visited[v])
        {
            parentNode[v] = u;
            cout << "  " << nodeName[u] << " -> " << nodeName[v]
                 << " : unvisited, recurse\n";
            dfs(v);
        }
        else if (v != parentNode[u])
        {
            // v is already visited and is not our direct parent, so
            // edge u-v is a back edge (closes a cycle back to an
            // ancestor). Report it only once per undirected edge.
            if (!reportedEdge[u][v] && !reportedEdge[v][u])
            {
                cout << "  " << nodeName[u] << " -> " << nodeName[v]
                     << " : already explored -> cycle edge\n";
                reportedEdge[u][v] = true;
                reportedEdge[v][u] = true;
                markCycle(u, v);
            }
        }
    }

    active[u] = false;
    cout << "Leave " << nodeName[u] << '\n';
}

int main()
{
    int edges[][2] = {
        {0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 5}, {4, 5}, {5, 6}, {6, 7}};

    for (auto &e : edges)
    {
        adj[e[0]][e[1]] = 1;
        adj[e[1]][e[0]] = 1;
    }

    for (int i = 0; i < N; ++i)
        parentNode[i] = -1;

    // Start from C.
    cout << "TASK 2 - DFS Vulnerability Exploration\n\n";
    cout << "Starting DFS at C\n\n";
    dfs(2);

    cout << "\nResult:\n";
    if (cycleFound)
    {
        cout << cycleCount << " cycle(s) detected.\n";
        cout << "UNSTABLE locations: ";
        for (int i = 0; i < N; ++i)
            if (cycleMarked[i])
                cout << nodeName[i] << ' ';
        cout << "\n";
    }
    else
    {
        cout << "No cycle detected; network is stable under this test.\n";
    }

    return 0;
}