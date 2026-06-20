#include <bits/stdc++.h>
using namespace std;

// Segment Tree - Point updates, Range queries
// Build:  O(n)
// Query:  O(log n)
// Update: O(log n)
// Space:  O(n), implemented as 4*n, 1-indexed
struct SegmentTree {
    int n;
    vector<long long> tree;

    static constexpr long long NEUTRAL = LLONG_MIN;

    static long long merge(long long a, long long b) {
        // Range Maximum Query
        return max(a, b);
    }

    SegmentTree(const vector<long long>& a) {
        n = (int)a.size();
        tree.assign(4 * n, NEUTRAL);
        build(1, 0, n-1, a);
    }

    void build(int node, int left, int right, const vector<long long>& a) {
        if (left == right) {
            tree[node] = a[left];
        } else {
            int mid = left + (right - left) / 2;

            build(2 * node, left, mid, a);
            build(2 * node + 1, mid + 1, right, a);

            tree[node] = merge(tree[node*2], tree[node*2 + 1]);
        }
    }

    // a[i] = value
    void update(int idx, long long value) {
        update(1, 0, n-1, idx, value);
    }

    void update(int node, int left, int right, int idx, long long value) {
        if (left == right) {
            tree[node] = value;
        } else {
            int mid = left + (right - left) / 2;

            if (idx <= mid) update(2 * node, left, mid, idx, value);
            if (idx > mid) update(2 * node + 1, mid + 1, right, idx, value);

            tree[node] = merge(tree[node*2], tree[node*2 + 1]);
        }
    }

    // query on range [l, r]
    long long query(int l, int r) const {
        return query(1, 0, n-1, l, r);
    }

    long long query(int node, int left, int right, int queryLeft, int queryRight) const {
        if (queryRight < left || right < queryLeft) return 0;

        if (queryLeft <= left && right <= queryRight) {
            return tree[node];
        } else {
            int mid = left + (right - left) / 2;

            return merge(
                query(node * 2, left, mid, queryLeft, queryRight),
                query(node * 2 + 1, mid + 1, right, queryLeft, queryRight)
            );
        }
    }
};