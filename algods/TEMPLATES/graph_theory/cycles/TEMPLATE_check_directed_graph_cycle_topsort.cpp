#include <bits/stdc++.h>
using namespace std;

vector<int> kahn_topsort(int n, vector<vector<int>>& adj) {
    vector<int> inDegree(n, 0);
    for (int i = 0; i < n; ++i)
        for (int v : adj[i])
            ++inDegree[v];

    queue<int> q;
    for (int i = 0; i < n; ++i) 
        if (inDegree[i] == 0)
            q.push(i);

    vector<int> topsort;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topsort.push_back(u);

        for (int v : adj[u]) {
            --inDegree[v];
            if (inDegree[v] == 0)
                q.push(v);
        }
    }

    if (topsort.size() != n) return {}; // cycle exists
    return topsort;
}

// Time: O(V+E) | Space: O(V)
// n = number of vertices | adj: adj list [returns: vector<int> topological sort and {} if cycle is detected]
bool cycle(int n, vector<vector<int>>& adj) {
    vector<int> topsort = kahn_topsort(n, adj);
    if (topsort.size() == 0) return true;
    else return false;
}