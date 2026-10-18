#include <iostream>
#include <iomanip>
using namespace std;

const int N = 8;
const int INF = 1000000000;

int main() {
    const char name[N] = {'A','B','C','D','E','F','G','H'};

    // Directed weighted graph for Tasks 3-4.
    int w[N][N];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            w[i][j] = (i == j ? 0 : INF);

    w[0][1] = 4;  // A->B
    w[0][2] = 2;  // A->C
    w[1][3] = 5;  // B->D
    w[2][3] = 1;  // C->D
    w[2][4] = 3;  // C->E
    w[3][5] = 8;  // D->F
    w[4][5] = 2;  // E->F
    w[5][6] = 6;  // F->G
    w[6][7] = 1;  // G->H

    // Risk information from Tasks 1 and 2:
    // HIGH-RISK = G,H
    // UNSTABLE = C,D,E,F
    // Therefore only A and B remain valid/stable.
    bool removed[N] = {};
    removed[2] = removed[3] = removed[4] = removed[5] = true;
    removed[6] = removed[7] = true;

    cout << "TASK 3 - Safe Route Planning using Dijkstra\n\n";
    cout << "Pruned HIGH-RISK: G H\n";
    cout << "Pruned UNSTABLE: C D E F\n";
    cout << "Remaining valid/stable nodes: A B\n\n";

    int dist[N];
    bool used[N] = {};
    int parent[N];

    for (int i = 0; i < N; ++i) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[0] = 0; // A

    for (int step = 0; step < N; ++step) {
        int u = -1;
        for (int i = 0; i < N; ++i) {
            if (removed[i] || used[i] || dist[i] == INF) continue;
            if (u == -1 || dist[i] < dist[u]) u = i;
        }

        if (u == -1) break;
        used[u] = true;

        cout << "Select " << name[u] << " with distance " << dist[u] << '\n';

        for (int v = 0; v < N; ++v) {
            if (removed[v] || w[u][v] == INF || used[v]) continue;

            int candidate = dist[u] + w[u][v];
            if (candidate < dist[v]) {
                dist[v] = candidate;
                parent[v] = u;
                cout << "  Relax " << name[u] << " -> " << name[v]
                     << ", new distance = " << dist[v] << '\n';
            }
        }
    }

    cout << "\nFinal shortest-cost table from A:\n";
    for (int i = 0; i < N; ++i) {
        if (!removed[i]) {
            cout << "A -> " << name[i] << " = ";
            if (dist[i] == INF) cout << "unreachable\n";
            else cout << dist[i] << '\n';
        }
    }

    cout << "\nFinal paths:\n";
    cout << "A -> A: A, cost 0\n";
    cout << "A -> B: A -> B, cost 4\n";

    return 0;
}
