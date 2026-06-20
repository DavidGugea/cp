#include <bits/stdc++.h>
using namespace std;

// Lazy Segment Tree - Range add updates, Range sum queries
// Build:        O(n)
// Range update: O(log n)
// Range query:  O(log n)
// Space:        O(n), implemented as 4*n, 1-indexed
struct LazySegmentTree {
    int n;
    vector<long long> tree;
    vector<long long> lazy;

    LazySegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, 0);
    }

    LazySegmentTree(const vector<long long>& a) {
        n = (int)a.size();
        tree.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, 0);
        build(1, 0, n-1, a);
    }

    void build(int node, int left, int right, const vector<long long>& a) {
        if (left == right) {
            tree[node] = a[left];
        } else {
            int mid = left + (right - left) / 2;

            build(2 * node, left, mid, a);
            build(2 * node + 1, mid + 1, right, a);

            pull(node);
        }
    }

    void pull(int node) {
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void apply(int node, int left, int right, long long value) {
        tree[node] += (right - left + 1LL) * value;
        lazy[node] += value;
    }

    void push(int node, int left, int right) {
        if (lazy[node] == 0 || left == right) return;

        int mid = left + (right - left) / 2;

        apply(node * 2, left, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, right, lazy[node]);

        lazy[node] = 0;
    }

    // add value to range [l, r]
    void add(int l, int r, long long value) {
        add(1, 0, n-1, l, r, value);
    }

    void add(int node, int left, int right, int rangeLeft, int rangeRight, long long value) {
        if (rangeRight < left || right < rangeLeft) return;

        if (rangeLeft <= left && right <= rangeRight) {
            apply(node, left, right, value);
        } else {
            push(node, left, right);
            int mid = left + (right - left) / 2;

            add(node * 2, left, mid, rangeLeft, rangeRight, value);
            add(node * 2 + 1, mid + 1, right, rangeLeft, rangeRight, value);

            pull(node);
        }
    }

    // query on [l, r]
    long long query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    long long query(int node, int left, int right, int queryLeft, int queryRight) {
        if (queryRight < left || right < queryLeft) return 0;

        if (queryLeft <= left && right <= queryRight) {
            return tree[node];
        } else {
            push(node, left, right);
            int mid = left + (right - left) / 2;
            return query(node * 2, left, mid, queryLeft, queryRight) + query(node * 2 + 1, mid + 1, right, queryLeft, queryRight);
        }
    }
};