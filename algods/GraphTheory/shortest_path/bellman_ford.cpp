#include <bits/stdc++.h>
using namespace std;

// O(V*E)
vector<int> bellmanFordAdjList(unordered_map<int, vector<pair<int, int>>>& adj, vector<int>& parent, int n, int source) {
    const int INF = 1e9;
    vector<int> dist(n, INF);
    parent.assign(n, -1);
    dist[source] = 0;

    for (int i = 0; i <= (n-1); ++i) {
        for (int u = 0; u < n; ++u) {
            if (dist[u] == INF) continue;
            for (auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                }
            }
        }
    }

    return dist;
}

// O(V^3)
vector<int> bellmanFordAdjMatrix(vector<vector<int>> adj, vector<int>& parent, int n, int source) {
    const int INF = 1e9;
    vector<int> dist(n, INF);
    parent.assign(n, -1);
    dist[source] = 0;

    for (int i = 0; i <= (n-1); ++i) {
        for (int u = 0; u < n; ++u) {
            if (dist[u] == INF) continue;
            for (int v = 0; v < n; ++v) {
                if (adj[u][v] != INF && dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    return dist;
}

vector<int> bellmanFord(vector<vector<int>> edges, vector<int>& parent, int n, int source) {
    const int INF = 1e9;
    vector<int> dist(n, INF);
    parent.assign(n, -1);
    dist[source] = 0;

    for (int i = 1; i < n; ++i) {
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
}

vector<int> restore_path(int source, int target, vector<int> const& p) {
    vector<int> path;

    for (int v = target; v != source; v = p[v])
        path.push_back(v);
    path.push_back(source);

    reverse(path.begin(), path.end());
    return path;
}