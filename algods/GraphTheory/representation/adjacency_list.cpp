#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // unordered_map<int, vector<int>> adj: adjacency list representation [node -> [list of neighbours]]

    int n, k; cin >> n >> k;
    unordered_map<int, vector<int>> adj;

    // directed graph representation
    for (int i = 0; i < k; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        // for undirected: adj[b].push_back(a);
    }

    return 0;
}