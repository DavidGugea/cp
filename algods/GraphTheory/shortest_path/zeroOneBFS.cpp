#include <bits/stdc++.h>
using namespace std;

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

                if (w == 1) dq.push_back(v);
                else dq.push_front(v);
            }
        }
    }

    return dist;
}