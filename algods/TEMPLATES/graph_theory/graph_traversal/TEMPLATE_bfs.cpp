#include <bits/stdc++.h>
using namespace std;

// BFS on adjacency matrix
// O(V^2)
vector<int> bfsAdjMatrix(vector<vector<int>>& adj, int source) {
    int n = adj.size();
    vector<bool> used(n, false);
    vector<int> bfsResult;

    queue<int> q;
    q.push(source);
    used[source] = true;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        bfsResult.push_back(v);

        for (int i = 0; i < n; ++i) {
            if (adj[v][i] == 1 && !used[i]) {
                used[i] = true;
                q.push(i);
            }
        }
    }

    return bfsResult;
}

// BFS on adjacency list
// O(V + E)
vector<int> bfsAdjList(unordered_map<int, vector<int>>& adj, int source) {
    int n = adj.size();
    vector<int> bfsResult;
    unordered_set<int> visited;

    queue<int> q;
    q.push(source);
    visited.insert(source);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        bfsResult.push_back(v);

        for (auto c : adj[v]) {
            if (!visited.count(c)) {
                visited.insert(c);
                q.push(c);
            }
        }
    }

    return bfsResult;
}