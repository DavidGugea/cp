#include <bits/stdc++.h>
using namespace std;

// Sparse graph (E << V^2): adj list
// Dense graph  (E ~= V^2): adj matrix
// Use adj list for sparse, adj matrix for dense

// SPFA = queue-based Bellman-Ford. Use case: Faster BF for sparse graphs

// Shorest Path Faster Algorithm (SPFA) (return true if dist is found, false if SPFA stops because of negative cycle). Implementation for adj list
// O(V*E)
// adj: adjacency list | parent : parent mapping to restore shortest paths (optional) | dist: distance array (result of SPFA) | n : no. of vertices | source : source vertex
bool spfa(unordered_map<int, vector<pair<int, int>>>& adj, vector<int>& parent, vector<int>& dist, int n, int source) {
    const int INF = 1e9;
    vector<bool> inQueue(n, false);
    vector<int> cnt(n, 0);
    dist.assign(n, INF);
    parent.assign(n, -1);
    dist[source] = 0;

    queue<int> q;
    q.push(source);
    inQueue[source] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        inQueue[u] = false;

        for (auto& [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;

                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;
                    ++cnt[v];
                    if (cnt[v] > n) return false;
                }
            }
        }
    }

    return true;
}

// Shorest Path Faster Algorithm (SPFA) (return true if dist is found, false if SPFA stops because of negative cycle). Implementation for adj matrix
// O(V^3)
// adj: adjacency matrix | parent : parent mapping to restore shortest paths (optional) | dist: distance array (result of SPFA) | n : no. of vertices | source : source vertex
bool spfa(vector<vector<int>>& adj, vector<int>& parent, vector<int>& dist, int n, int source) {
    const int INF = 1e9;
    vector<bool> inQueue(n, false);
    vector<int> cnt(n, 0);
    dist.assign(n, INF);
    parent.assign(n, -1);
    dist[source] = 0;

    queue<int> q;
    q.push(source);
    inQueue[source] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        inQueue[u] = false;

        for (int v = 0; v < n; ++v) {
            if (adj[u][v] != INF && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
                parent[v] = u;

                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;
                    ++cnt[v];
                    if (cnt[v] > n) return false;
                }
            }
        }
    }

    return true;
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