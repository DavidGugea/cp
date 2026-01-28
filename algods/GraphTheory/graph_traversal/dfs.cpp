#include <bits/stdc++.h>
using namespace std;

// DFS on adjacency matrix
vector<int> dfsAdjMatrix(vector<vector<int>>& adj, int source) {
    int n = adj.size();
    vector<bool> used(n, false);
    vector<int> dfsResult;

    stack<int> s;
    s.push(source);
    used[source] = true;
    while (!s.empty()) {
        int v = s.top(); s.pop();
        dfsResult.push_back(v);

        for (int i = 0; i < n; ++i) {
            if (adj[v][i] == 1 && !used[i]) {
                used[i] = true;
                s.push(i);
            }
        }
    }

    return dfsResult;
}

// DFS on adjacency list
vector<int> dfsAdjList(unordered_map<int, vector<int>>& adj, int source) {
    int n = adj.size();
    vector<int> dfsResult;
    unordered_set<int> visited;

    stack<int> s;
    s.push(source);
    visited.insert(source);
    while (!s.empty()) {
        int v = s.top(); s.pop();
        dfsResult.push_back(v);

        for (auto c : adj[v]) {
            if (!visited.count(c)) {
                visited.insert(c);
                s.push(c);
            }
        }
    }

    return dfsResult;
}

// recursive DFS on adjacency list
void dfsAdjListRecursive(int v, unordered_map<int, vector<int>>& adj, vector<int>& dfsResult, unordered_set<int>& visited) {
    visited.insert(v);
    dfsResult.push_back(v);

    for (auto c : adj[v]) {
        if (!visited.count(c)) {
            dfsAdjListRecursive(c, adj, dfsResult, visited);
        }
    }
}

// recursive DFS on adjacency matrix
void dfsAdjMatrixRecursive(int v, vector<vector<int>>& adj, vector<int>& dfsResult, vector<bool>& visited) {
    int n = adj.size();
    visited[v] = true;
    dfsResult.push_back(v);

    for (int i = 0; i < n; ++i) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfsAdjMatrixRecursive(i, adj, dfsResult, visited);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}