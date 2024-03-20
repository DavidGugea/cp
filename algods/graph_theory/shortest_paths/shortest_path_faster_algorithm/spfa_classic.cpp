#include <bits/stdc++.h>
using namespace std;

// doesn't detect negative cycles
vector<int> spfa(vector<vector<pair<int, int>>> adj, int s) {
    const int INF = 1e9+9;
    vector<int> d(adj.size(), INF);
    d[s] = 0;
    queue<int> q;
    vector<bool> inqueue(adj.size(), false);
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        inqueue[v] = false;

        for (int from = 0; from < adj.size(); ++from) {
            for (pair<int, int> p : adj[from]) {
                int to = p.first;
                int cost = p.second;

                if (d[from] + cost < d[to]) {
                    // relaxation
                    d[to] = d[from] + cost;

                    if (!inqueue[to]) {
                        q.push(to);
                        inqueue[to] = true;
                    }
                }
            }
        }
    }

    return d;
}