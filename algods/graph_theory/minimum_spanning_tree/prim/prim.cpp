#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+9;

struct Edge {
    int w = INF, to = -1;
};

// O(N^2)
void prim(int n, vector<vector<int>> adj) {
    // n -> number of veritces
    // adj -> adjacency list of weighted graph

    int total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = 0;

    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!selected[j] && (v==-1 || min_e[j].w < min_e[v].w))
                v=j;

        if (min_e[v].w == INF) {
            cout << "No MST" << "\n";
            return;
        }

        selected[v] = true;
        total_weight += min_e[v].w;

        for (int to = 0; to < n; ++to) {
            if (adj[v][to] < min_e[to].w)
                min_e[to] = {adj[v][to], v};
        }
    }
}