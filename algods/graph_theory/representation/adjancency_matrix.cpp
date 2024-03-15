#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // edge from i to j    => adj[i][j] = 1
    // no edge from i to j => adj[i][j] = 0

    // n = vertex amount
    int n, k; cin >> n >> k;
    vector<vector<int>> adj(n, vector<int>(n));

    /*
    input:
    n, k
    i1 j1
    i2 j2
    i3 j3
    i4 j4
    i5 j5
    */

    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}