#include <bits/stdc++.h>
using namespace std;

// Sparse graph (E << V^2): adj list
// Dense graph  (E ~= V^2): adj matrix
// Use adj list for sparse, adj matrix for dense

// Bellman Ford adjacency list
// O(V*E)
// adj: adjacency list | parent : parent mapping to restore shortest paths (optional) | n : no. of vertices | source : source vertex
vector<int> bellmanFordAdjList(unordered_map<int, vector<pair<int, int>>>& adj, vector<int>& parent, int n, int source) {
    const int INF = 1e9;
    vector<int> dist(n, INF);
    parent.assign(n, -1);
    dist[source] = 0;

    for (int i = 0; i < n-1; ++i) {
        bool changed = false;
        for (int u = 0; u < n; ++u) {
            if (dist[u] == INF) continue;
            for (auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    changed = true;
                }
            }
        }
        if (!changed) break;
    }

    return dist;
}

// Bellman Ford adjacency matrix
// O(V^3)
// adj: adjacency matrix | parent : parent mapping to restore shortest paths (optional) | n : no. of vertices | source : source vertex
vector<int> bellmanFordAdjMatrix(vector<vector<int>> adj, vector<int>& parent, int n, int source) {
    const int INF = 1e9;
    vector<int> dist(n, INF);
    parent.assign(n, -1);
    dist[source] = 0;

    for (int i = 0; i < n-1; ++i) {
        bool changed = false;
        for (int u = 0; u < n; ++u) {
            if (dist[u] == INF) continue;
            for (int v = 0; v < n; ++v) {
                if (adj[u][v] != INF && dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                    parent[v] = u;
                    changed = true;
                }
            }
        }
        if (!changed) break;
    }

    return dist;
}

// Bellman Ford edges
// O(V*E)
// edges : list of edges | parent : parent mapping to restore shortest paths (optional) | n : no. of vertices | source : source vertex
vector<int> bellmanFordEdges(vector<vector<int>> edges, vector<int>& parent, int n, int source) {
    const int INF = 1e9;
    vector<int> dist(n, INF);
    parent.assign(n, -1);
    dist[source] = 0;

    for (int i = 0; i < n-1; ++i) {
        bool changed = false;
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;

                changed = true;
            }
        }
        if (!changed) break;
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