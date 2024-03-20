#include <bits/stdc++.h>
using namespace std;

// You are given a directed or undirected weighted graph with n vertices and m edges. The weights of all edges are non-negative. You are also given a starting vertex s. Dijkstra gives you the lengths of the shortest paths from a starting vertex s to all other vertices, and outputs the shortest paths themselves.

void dijkstra(int s, vector<int>& d, vector<int>& p, vector<vector<pair<int, int>>> adj) {
    // s: starting vertex
    // d: vector that contains the distances from the starting vertex to the rest
    // p: predecessors vector
    // adj: graph stored in an adjacency list, adj[v] contains the list of edges going from this vertex: pair<int, int> where the first element is the vertex and the second element is the weight of the edge

    const int INF = 1e9+9; 
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false); // use this to mark vertices as visited or unvisited

    d[s] = 0;
    for (int i = 0; i < n; ++i) {
        // iterate throughout all nodes and find the one with the smallest distance that hasn't been visited yet
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        // if the distance is infinity, that means that the vertex can't be reached and the other nodes have gone through the process of 'relaxation', so we can stop here.
        if (d[v] == INF)
            break;

        // iterate through all the vertices that V points towards and perform relaxation
        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

vector<int> restore_path(int s, int t, vector<int> const& p) {
    // restore path from the starting vertex s to any vertex t where p is the predecessor list
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}