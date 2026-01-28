#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // edge from i to j    -> adj[i][j] = 1;
    // no edge from i to j -> adj[i][j] = 0;

    int n, k; cin >> n >> k;
    vector<vector<int>> adj(n, vector<int>(n));

    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }

    return 0;
}