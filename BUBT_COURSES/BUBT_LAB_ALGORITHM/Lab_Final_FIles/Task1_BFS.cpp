#include <iostream>
using namespace std;

int main()
{
    const int N = 8;
    const char node[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    // Unweighted graph: A-B, A-C, B-D, C-D, C-E, D-F, E-F, F-G, G-H
    int adj[N][N] = {};
    int edges[][2] = {
        {0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 5}, {4, 5}, {5, 6}, {6, 7}};

    for (auto &e : edges)
    {
        adj[e[0]][e[1]] = 1;
        adj[e[1]][e[0]] = 1; // undirected for Tasks 1-2
    }

    bool visited[N] = {};
    int level[N];
    for (int i = 0; i < N; ++i)
        level[i] = -1;

    // Manual queue so the BFS logic is explicit.
    int q[N];
    int front = 0, rear = 0;

    int start = 0; // A
    visited[start] = true;
    level[start] = 0;
    q[rear++] = start;

    cout << "TASK 1 - BFS Emergency Spread Mapping\n\n";
    cout << "Queue/intermediate steps:\n";

    while (front < rear)
    {
        int u = q[front++];
        cout << "Dequeue " << node[u] << " (Layer " << level[u] << ")";
        cout << " | Queue: ";
        for (int k = front; k < rear; ++k)
            cout << node[q[k]] << ' ';
        cout << '\n';

        for (int v = 0; v < N; ++v)
        {
            if (adj[u][v] && !visited[v])
            {
                visited[v] = true;
                level[v] = level[u] + 1;
                q[rear++] = v;
                cout << "  Discover " << node[v]
                     << " -> Layer " << level[v] << '\n';
            }
        }
    }

    cout << "\nFinal layers:\n";
    for (int L = 0; L <= 5; ++L)
    {
        cout << "Layer " << L << ": ";
        bool any = false;
        for (int i = 0; i < N; ++i)
        {
            if (level[i] == L)
            {
                cout << node[i] << ' ';
                any = true;
            }
        }
        if (!any)
            cout << "(none)";
        cout << '\n';
    }

    cout << "\nHIGH-RISK zones (last two layers): G, H\n";
    return 0;
}
