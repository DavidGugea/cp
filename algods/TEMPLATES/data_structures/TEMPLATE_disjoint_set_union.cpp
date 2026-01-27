#include <bits/stdc++.h>
using namespace std;

// make_set(v): O(1)
// find_set(v): O(α(n)) amortized (path compression)
// union_sets(a, b): O(α(n)) amortized (union by size)
class DisjointSetUnion {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> size;

    void make_set(int v) {
        if (parent.find(v) != parent.end())
            return;

        parent[v] = v;
        size[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;

        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
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