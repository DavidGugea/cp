#include <bits/stdc++.h>
using namespace std;

void bfs01(int s, vector<int>& d, vector<int>& p, vector<vector<pair<int, int>>> adj) {
    const int INF = 1e9+9;
    int n = adj.size();
    vector<int> (n, INF);
    deque<int> q;
    q.push_front(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();

        for (pair<int, int> edge : adj[v]) {
            int u = edge.first;
            int w = edge.second;

            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;

                if (w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }
}