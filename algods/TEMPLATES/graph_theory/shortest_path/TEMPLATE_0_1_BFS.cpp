#include <bits/stdc++.h>
using namespace std;

// Sparse graph (E << V^2): adj list + priority queue -> O((V+E)logV)
// Dense graph  (E ~= V^2): adj matrix + linear min selection -> O(V^2)
// Use adj list for sparse, adj matrix for dense

// 0-1 BFS = deque-based Dijkstra for edges with 0/1 weights. Use case: Sparse 0-1 graphs

// 0-1 BFS with adj list
// O(V+E)
// adj: adjacency list | parent : parent mapping to restore shortest paths (optional) | n : no. of vertices | source : source vertex
vector<int> zeroOneBFS(unordered_map<int, vector<pair<int, int>>>& adj, vector<int>& parent, int n, int source) {
    const int INF = 1e9;
    vector<int> dist(n, INF);
    parent.assign(n, -1);

    deque<int> dq;
    dist[source] = 0;
    dq.push_back(source);

    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;

                if (w == 0) dq.push_front(v);
                else dq.push_back(v);
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