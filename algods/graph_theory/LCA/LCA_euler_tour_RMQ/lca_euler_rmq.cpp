#include <bits/stdc++.h>
using namespace std;

int log2_floor(unsigned long long i)
{
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

struct LCA {
    vector<int> height, euler, first, depth;
    vector<vector<pair<int, int>>> st; // sparse table RMQ for LCA queries
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>>& adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);

        // construct depth using euler and height
        for (int i = 0; i < euler.size(); ++i)
            depth.push_back(height[euler[i]]);

        // initialize the first row of the sparse table using the depth array
        int stn = depth.size();
        int dpr = log2_floor(stn) + 1;
        // pair<int, int> -> first: depth, second: vertex id
        st.assign(dpr, vector<pair<int, int>>(stn));

        for (int i = 0; i < st[0].size(); ++i)
            st[0][i] = make_pair(depth[i], euler[i]);

        for (int i = 1; i <= dpr; i++) {
            for (int j = 0; j + (1 << i) <= stn; j++) {
                pair<int, int> f = st[i-1][j];
                pair<int, int> s = st[i - 1][j + (1 << (i - 1))];
                if (f.first < s.first) {
                    st[i][j] = make_pair(f.first, f.second);
                } else {
                    st[i][j] = make_pair(s.first, s.second);
                }
            }
        }
    }

    void dfs(vector<vector<int>>& adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    int query(int a, int b) {
        int l = min(first[a], first[b]);
        int r = max(first[a], first[b]);

        cout << l << " " << r << "\n";

        int p = log2_floor(r - l + 1);
        int k = 1<<p;
        pair<int, int> f = st[p][l];
        pair<int, int> s = st[p][r-k+1];
        if (f.first < s.first) {
            return f.second;
        } else {
            return s.second;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    /*
example graph for input:
17
2 1 2
2 3 4
3 5 6 7
2 8 9
0
2 10 11
0
2 12 13
0
0
0
3 14 15 16
0
0
0
0
0

    */

    int n;
    cin >> n;
    vector<vector<int>> adj;
    for (int i = 0; i < n; ++i) {
        vector<int> node;
        int c; cin >> c;
        for (int j = 0; j < c; ++j) {
            int val; cin >> val;
            node.push_back(val);
        }
        adj.push_back(node);
    }
    /*
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (auto j : adj[i]) {
            cout << j <<  " ";
        }
        cout << "\n";
    }
    */
    LCA* lca = new LCA(adj);

    // answer n LCA queries
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        int result = lca->query(a, b);
        cout << result << "\n";
    }

    return 0;
}