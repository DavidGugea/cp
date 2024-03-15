#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> adj, int n, int s) {
    // adj -> adjancency list representation
    // n   -> number of nodes
    // s   -> source vertex

    queue<int> q;
    vector<bool> used(n);
    vector<int> bfs;

    q.push(s);
    bfs.push(s);
    used[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                bfs.push(u);
            }
        }
    }

    return bfs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}