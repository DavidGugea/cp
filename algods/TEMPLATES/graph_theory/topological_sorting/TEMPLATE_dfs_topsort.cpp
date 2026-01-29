#include <bits/stdc++.h>
using namespace std;

void dfs(int source, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& topsort) {
    visited[source] = true;

    for (int u : adj[source])
        if (!visited[u])
            dfs(u, adj, visited, topsort);

    topsort.push_back(source);
}

// DFS topological sorting
// Time: O(V+E) | Space: O(V)
// n = number of vertices | adj: adj list [returns: vector<int> topological sort and {} if cycle is detected]
vector<int> topsort(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    vector<int> topsort_result;
    for (int i = 0; i < n; ++i)
        if (!visited[i])
            dfs(i, adj, visited, topsort_result);

    reverse(topsort_result.begin(), topsort_result.end());
    return topsort_result;
}