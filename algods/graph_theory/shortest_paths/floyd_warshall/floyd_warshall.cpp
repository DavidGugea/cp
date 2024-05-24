#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(vector<vector<int>>& d, vector<vector<int>> graph, int n) {
    // distance array: empty // NXN matrix
    // graph: adjacency matrix graph NXN matrix
    // number of nodes inside the graph

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i==j)
                d[i][j] = 0;
            else if (graph[i][j] != 0)
                d[i][j] = graph[i][j];

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}