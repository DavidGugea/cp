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
        // adj is ADJ LIST
        n = adj.size();
        height.resize(n);
        first.resize(n);
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