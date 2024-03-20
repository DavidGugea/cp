#include <bits/stdc++.h>
using namespace std;

void dijkstra_optimization(int s, vector<int>& d, vector<int>& p) {
    const int INF = 1e9+9;
    vector<vector<pair<int, int>>> adj;

    int n = adj.size();
    p.assign(n, -1);

    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (pair<int, int>edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}