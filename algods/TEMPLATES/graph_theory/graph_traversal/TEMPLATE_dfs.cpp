#include <bits/stdc++.h>
using namespace std;

vector<int> dfs(vector<vector<int>> adj, int n, int src) {
    // adj -> adjacency list
    // n -> number of vertices
    // s -> source vertex

    stack<int> s;
    vector<bool> used(n);
    vector<int> dfs;

    s.push(src);
    dfs.push(src);
    used[src] = true;

    while (!q.empty()) {
        int v = s.top();
        s.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                s.push(u);
                dfs.push(u);
            }
        }
    }

    return dfs;
}