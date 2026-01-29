#include <bits/stdc++.h>
using namespace std;

// Find if there is a cycle or not in a directed graph represented by an adjacency list using DFS

bool dfsCycle(int source, unordered_map<int, vector<int>>& adj, vector<bool>& recursion_stack, vector<bool>& visited) {
    // set source as part of the recursion stack
    recursion_stack[source] = true;
    visited[source] = true;

    // check every neighbor
    for (int v : adj[source]) {
        if (!visited[v] && dfsCycle(v, adj, recursion_stack, visited)) return true;
        else if (visited[v] && recursion_stack[v]) return true; // if the neighbour is already in the recursion stack => there's an edge to a vertex already in the stack => cycle
    }

    // pop the source out of the recursion stack
    recursion_stack[source] = false;
    return false;
}

// O(V+E)
// n = number of vertices, adj = adjacency list
bool cycle(int n, unordered_map<int, vector<int>>& adj) {
    vector<bool> recursion_stack(n, false);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i] && dfsCycle(i, adj, recursion_stack, visited)) return true;
    }

    return false;
}