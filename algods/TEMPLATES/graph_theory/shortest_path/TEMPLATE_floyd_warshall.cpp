#include <bits/stdc++.h>
using namespace std;

// Floyd Warshall (All-Pairs Shortest Path)
// O(V^3)
// adj: adjancency matrix | n: no. of vertices
// returns: dist: all-pairs shortest path: dist[i][j] = shortest path from i to j
vector<vector<int>> floydWarshall(vector<vector<int>> adj, int n) {
    const int INF = 1e9;
    vector<vector<int>> dist = adj;

    for (int i = 0; i < n; ++i) dist[i][i] = 0;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = max(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    return dist;
}