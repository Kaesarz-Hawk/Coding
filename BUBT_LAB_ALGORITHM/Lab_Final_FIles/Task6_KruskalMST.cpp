#include <iostream>
using namespace std;

const int N = 8;

struct Edge
{
    int u, v, w;
};

int parentDSU[N];
int rankDSU[N];

int findSet(int x)
{
    if (parentDSU[x] == x)
        return x;
    return parentDSU[x] = findSet(parentDSU[x]);
}

bool unite(int a, int b)
{
    a = findSet(a);
    b = findSet(b);

    if (a == b)
        return false;

    if (rankDSU[a] < rankDSU[b])
    {
        parentDSU[a] = b;
    }
    else if (rankDSU[a] > rankDSU[b])
    {
        parentDSU[b] = a;
    }
    else
    {
        parentDSU[b] = a;
        rankDSU[a]++;
    }
    return true;
}

void sortEdges(Edge e[], int m)
{
    for (int i = 1; i < m; ++i)
    {
        Edge key = e[i];
        int j = i - 1;

        while (j >= 0 && e[j].w > key.w)
        {
            e[j + 1] = e[j];
            --j;
        }
        e[j + 1] = key;
    }
}

int main()
{
    const char name[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    // HIGH-RISK: G, H
    // UNSTABLE: C, D, E, F
    // Valid/stable nodes: A, B
    Edge edges[] = {
        {0, 1, 4} // A - B
    };
    const int M = 1;

    for (int i = 0; i < N; ++i)
    {
        parentDSU[i] = i;
        rankDSU[i] = 0;
    }

    cout << "TASK 6 - Kruskal Minimum Spanning Tree\n\n";
    cout << "Removed HIGH-RISK nodes: G H\n";
    cout << "Removed UNSTABLE nodes: C D E F\n";
    cout << "Valid/stable nodes: A B\n\n";

    sortEdges(edges, M);

    int totalCost = 0;
    int selected = 0;

    cout << "Edges considered in increasing cost order:\n";

    for (int i = 0; i < M; ++i)
    {
        cout << name[edges[i].u] << " - " << name[edges[i].v]
             << " (" << edges[i].w << "): ";

        if (unite(edges[i].u, edges[i].v))
        {
            cout << "SELECTED\n";
            totalCost += edges[i].w;
            selected++;
        }
        else
        {
            cout << "REJECTED (would form a cycle)\n";
        }
    }

    cout << "\nSelected MST edges:\n";
    cout << "A - B (4)\n";
    cout << "Total infrastructure cost = " << totalCost << '\n';
    cout << "Cycle check: no cycle in the resulting tree.\n";

    if (selected == 1)
        cout << "All valid/stable nodes A and B are connected.\n";

    return 0;
}