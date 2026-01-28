#include <bits/stdc++.h>
using namespace std;

// O(ElogV)
long long primAdjList(unordered_map<int, vector<pair<int, int>>>& adj, int n) {
    const int INF = 1e9;
    vector<bool> inMST(n, false);
    vector<int> key(n, INF); // min edge weight to connect vertex

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[0] = 0;
    pq.push({0, 0}); // start with vertex 0

    long long MSTweight = 0;
    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (inMST[u]) continue;

        inMST[u] = true;
        MSTweight += w;

        for (auto [v, w] : adj[u]) {
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                pq.push({w, v});
            }
        }
    }

    return MSTweight;
}

// O(V^2)
long long primAdjMatrix(vector<vector<int>>& adj, int n) {
    const int INF = 1e9;
    vector<int> key(n, INF);
    vector<bool> inMST(n, false);

    key[0] = 0;
    long long MSTWeight = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!inMST[j] && (u == -1 || key[j] < key[u]))
                u = j;
        }

        inMST[u] = true;
        MSTWeight += key[u];

        for (int v = 0; v < n; ++v) {
            if (!inMST[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
            }
        }
    }

    return MSTWeight;
}