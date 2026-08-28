#include <iostream>
#include <iomanip>
using namespace std;

const int N = 8;
const int INF = 1000000000;

void printMatrix(int d[N][N], const char name[N]) {
    cout << "      ";
    for (int j = 0; j < N; ++j) cout << setw(5) << name[j];
    cout << '\n';

    for (int i = 0; i < N; ++i) {
        cout << setw(5) << name[i] << ' ';
        for (int j = 0; j < N; ++j) {
            if (d[i][j] >= INF / 2) cout << setw(5) << "INF";
            else cout << setw(5) << d[i][j];
        }
        cout << '\n';
    }
}

int main() {
    const char name[N] = {'A','B','C','D','E','F','G','H'};

    int d[N][N];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            d[i][j] = (i == j ? 0 : INF);

    // Task 5: treat weighted connections as UNDIRECTED.
    int edges[][3] = {
        {0,1,4},{0,2,2},{1,3,5},{2,3,1},{2,4,3},
        {3,5,8},{4,5,2},{5,6,6},{6,7,1}
    };

    for (auto &e : edges) {
        d[e[0]][e[1]] = e[2];
        d[e[1]][e[0]] = e[2];
    }

    cout << "TASK 5 - Floyd-Warshall All-Pairs Shortest Paths\n\n";
    cout << "Initial distance matrix:\n";
    printMatrix(d, name);

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (d[i][k] < INF && d[k][j] < INF &&
                    d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }

        cout << "\nAfter allowing " << name[k] << " as an intermediate:\n";
        printMatrix(d, name);
    }

    int maxDist = -1;
    int maxI = -1, maxJ = -1;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (d[i][j] < INF && d[i][j] > maxDist) {
                maxDist = d[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }

    cout << "\nFinal all-pairs shortest-distance matrix:\n";
    printMatrix(d, name);

    cout << "\nLargest finite shortest-path distance: "
         << name[maxI] << " <-> " << name[maxJ]
         << " = " << maxDist << '\n';

    cout << "Interpretation: this pair has the lowest communication efficiency "
         << "because it requires the greatest minimum total cost.\n";

    return 0;
}
