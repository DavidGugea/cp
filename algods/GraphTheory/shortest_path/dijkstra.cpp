#include <bits/stdc++.h>
using namespace std;

// Dijkstra adjacency list implementation
vector<int> dijsktraAdjList(unordered_map<int, vector<pair<int, int>>>& adj, int n, int source) {
    const int INF = 1e9;
    vector<int> dist(n, INF);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto& [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

// Dijkstra adjacency matrix implementation
vector<int> dijsktraAdjMatrix(vector<vector<int>>& adj, int n, int source) {
    const int INF = 1e9;
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    dist[source] = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        if (dist[u] == INF) break;
        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (adj[u][v] != INF && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    return dist;
}