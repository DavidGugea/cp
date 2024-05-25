#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> size;

    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    int find_set(int v) {
        // path compression
        if (v == parent[v])
            return v;

        size[parent[v]] -= 1;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        // union by size => a > b, attach b to a
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);

            parent[b] = a;
            size[a] += size[b];
        }
    }
};

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<Edge> kruskal(int n, vector<Edge> edges) {
    int cost = 0;
    vector<Edge> result;
    DSU* dsu = new DSU();
    for (int i = 0; i < n; ++i)
        dsu->make_set(i);

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (dsu->find_set(e.u) != dsu->find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            dsu->union_sets(e.u, e.v);
        }

        if (result.size() == n-1)
            break;
    }

    return result;
}