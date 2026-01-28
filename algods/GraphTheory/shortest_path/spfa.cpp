#include <bits/stdc++.h>
using namespace std;

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