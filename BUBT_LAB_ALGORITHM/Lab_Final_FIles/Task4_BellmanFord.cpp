#include <iostream>
using namespace std;

const int N = 8;
const int M = 9;
const int INF = 1000000000;

struct Edge {
    int u, v, w;
};

int main() {
    const char name[N] = {'A','B','C','D','E','F','G','H'};

    // Modified directed weighted graph:
    // C-D = -2 and E-F = -1.
    Edge edges[M] = {
        {0,1,4}, {0,2,2}, {1,3,5}, {2,3,-2}, {2,4,3},
        {3,5,8}, {4,5,-1}, {5,6,6}, {6,7,1}
    };

    int dist[N];
    int parent[N];

    for (int i = 0; i < N; ++i) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[0] = 0; // A

    cout << "TASK 4 - Bellman-Ford with negative weights\n\n";

    // Bellman-Ford: relax all edges N-1 times.
    for (int pass = 1; pass <= N - 1; ++pass) {
        bool changed = false;

        cout << "Pass " << pass << ": ";

        for (int i = 0; i < M; ++i) {
            int u = edges[i].u;
            int v = edges[i].v;
            int wt = edges[i].w;

            if (dist[u] != INF && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                parent[v] = u;
                changed = true;
            }
        }

        for (int i = 0; i < N; ++i) {
            cout << name[i] << '=';
            if (dist[i] == INF) cout << "INF ";
            else cout << dist[i] << ' ';
        }
        cout << '\n';

        if (!changed) {
            cout << "No changes; algorithm can stop early.\n";
            break;
        }
    }

    // Extra pass detects a reachable negative-weight cycle.
    bool negativeCycle = false;
    for (int i = 0; i < M; ++i) {
        int u = edges[i].u, v = edges[i].v, wt = edges[i].w;
        if (dist[u] != INF && dist[u] + wt < dist[v]) {
            negativeCycle = true;
            break;
        }
    }

    cout << "\nFinal shortest distances from A:\n";
    for (int i = 0; i < N; ++i) {
        cout << "A -> " << name[i] << " = ";
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }

    cout << "\nNegative-weight cycle: "
         << (negativeCycle ? "YES" : "NO") << '\n';

    if (!negativeCycle)
        cout << "Conclusion: negative edges exist, but they do not create a negative cycle.\n";

    return 0;
}
