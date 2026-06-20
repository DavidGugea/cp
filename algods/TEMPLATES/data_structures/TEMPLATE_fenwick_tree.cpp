#include <bits/stdc++.h>
using namespace std;

// Fenwick Tree / Binary Indexed Tree (1-indexed)
// Point updates + Range sum queries

// Build: O(n)
// Point update: O(log n)
// Prefix sum: O(log n)
// Range sum: O(log n)
// Space: O(n)
struct FenwickTree {
    int n;
    vector<long long> bit;

    FenwickTree(int n) : n(n), bit(n + 1, 0) {}

    FenwickTree(const vector<long long>& a) {
        n = (int)a.size();
        bit.assign(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            bit[i] += a[i-1];

            int j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    }

    void add(int idx, long long delta) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += delta;
        }
    }

    long long prefix_sum(int idx) const {
        long long res = 0;

        for (; idx > 0; idx -= idx & -idx) {
            res += bit[idx];
        }

        return res;
    }

    long long query(int l, int r) const {
        if (l > r) return 0;
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};