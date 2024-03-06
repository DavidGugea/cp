#include <bits/stdc++.h>
using namespace std;

// fenwick tree/binary indexed tree(BIT)
// query: O(log N)
// point update: O(log N)
// construction O(N log N)
class FenwickTree {
public:
    vector<int> bit; // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); ++i)
            add(i, a[i]);
    }

    int sum(int idx) {
        int res = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l-1);
    }

    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};