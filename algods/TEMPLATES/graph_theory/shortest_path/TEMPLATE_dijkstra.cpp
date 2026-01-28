#include <bits/stdc++.h>
using namespace std;

// Sparse graph (E << V^2): adj list + priority queue -> O((V+E)logV)
// Dense graph  (E ~= V^2): adj matrix + linear min selection -> O(V^2)
// Use adj list for sparse, adj matrix for dense

// Dijkstra adjacency list implementation with priority queue
// adj: adjacency list | parent : parent mapping to restore shortest paths (optional) | n : no. of vertices | source : source vertex
// O((V+E)logV)
vector<int> dijsktraAdjList(unordered_map<int, vector<pair<int, int>>>& adj, vector<int>& parent, int n, int source) {
    const int INF = 1e9;
    vector<int> dist(n, INF);
    parent.assign(n, -1);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto& [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;

                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

// Dijkstra adjacency matrix implementation with linear min selection
// adj: adjacency matrix | parent : parent mapping to restore shortest paths (optional) | n : no. of vertices | source : source vertex
// O(V^2)
vector<int> dijsktraAdjMatrix(vector<vector<int>>& adj, vector<int>& parent, int n, int source) {
    const int INF = 1e9;
    vector<int> dist(n, INF);
    parent.assign(n, -1);
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
                parent[v] = u;
            }
        }
    }

    return dist;
}

// Given a path array, restore the shorest path source->target
vector<int> restore_path(int source, int target, vector<int> const& p) {
    vector<int> path;

    for (int v = target; v != source; v = p[v])
        path.push_back(v);
    path.push_back(source);

    reverse(path.begin(), path.end());
    return path;
}