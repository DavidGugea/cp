#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+9;

struct Edge {
    int w = INF, to = -1;
    bool operator<(Edge const& other) const {
        return make_pair(w, to) < make_pair(other.w, other.to);
    }
};

void prim(int n, vector<vector<Edge>> adj) {
    int total_weight = 0;

    vector<Edge> min_e(n);
    min_e[0].w = 0;

    set<Edge> q;
    q.insert({0, 0});

    vector<bool> selected(n, false);

    for (int i = 0; i < n; ++i) {
        int v = q.begin()->to;
        selected[v] = true;
        total_weight += q.begin()->w;
        q.erase(q.begin());

        for (Edge e : adj[v]) {
            if (!selected[v] && e.w < min_e[e.to].w) {
                q.erase({min_e[e.to].w, e.to});
                min_e[e.to] = {e.w, e.to};
                q.insert({e.w, e.to});
            }
        }
    }
}