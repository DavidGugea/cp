#include <bits/stdc++.h>
using namespace std;

class dsu {
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