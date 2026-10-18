#include <iostream>
using namespace std;

const int N = 8;

int bfs(int residual[N][N], int source, int sink, int parent[N]) {
    bool visited[N] = {};
    int q[N];
    int front = 0, rear = 0;

    q[rear++] = source;
    visited[source] = true;
    parent[source] = -1;

    while (front < rear) {
        int u = q[front++];

        for (int v = 0; v < N; ++v) {
            if (!visited[v] && residual[u][v] > 0) {
                visited[v] = true;
                parent[v] = u;
                q[rear++] = v;

                if (v == sink)
                    return 1;
            }
        }
    }

    return 0;
}

int main() {
    const char name[N] = {'A','B','C','D','E','F','G','H'};

    // Directed capacities are the listed weights.
    int capacity[N][N] = {};

    capacity[0][1] = 4; // A->B
    capacity[0][2] = 2; // A->C
    capacity[1][3] = 5; // B->D
    capacity[2][3] = 1; // C->D
    capacity[2][4] = 3; // C->E
    capacity[3][5] = 8; // D->F
    capacity[4][5] = 2; // E->F
    capacity[5][6] = 6; // F->G
    capacity[6][7] = 1; // G->H

    int residual[N][N];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            residual[i][j] = capacity[i][j];

    int source = 0; // A
    int sink = 7;   // H
    int parent[N];
    int maxFlow = 0;
    int iteration = 0;

    cout << "TASK 7 - Maximum Resource Flow (Edmonds-Karp)\n\n";

    while (bfs(residual, source, sink, parent)) {
        iteration++;

        int pathFlow = 1000000000;

        // Find bottleneck capacity on the augmenting path.
        int v = sink;
        while (v != source) {
            int u = parent[v];
            if (residual[u][v] < pathFlow)
                pathFlow = residual[u][v];
            v = u;
        }

        cout << "Augmenting path " << iteration << ": ";

        int path[N], len = 0;
        v = sink;
        while (v != -1) {
            path[len++] = v;
            if (v == source) break;
            v = parent[v];
        }

        for (int i = len - 1; i >= 0; --i) {
            cout << name[path[i]];
            if (i > 0) cout << " -> ";
        }
        cout << " | bottleneck = " << pathFlow << '\n';

        // Update residual capacities.
        v = sink;
        while (v != source) {
            int u = parent[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
            v = u;
        }

        maxFlow += pathFlow;
        cout << "  Current total flow = " << maxFlow << '\n';
    }

    cout << "\nFinal maximum flow from A to H = " << maxFlow << '\n';
    cout << "Final bottleneck: G -> H has capacity 1, so the maximum possible flow is 1.\n";

    return 0;
}
