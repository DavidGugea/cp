#include <bits/stdc++.h>
using namespace std;

// Dynamic Lazy Segment Tree - Large coordinate range, range add update, range sum query
// Update: O(log C)
// Query:  O(log C)
// Space:  O(number of created nodes)
// C = size of coordinate universe
// Initialize with q*64 for q operations (if known)
struct DynamicLazySegmentTree {
    struct Node{
        long long sum = 0;
        long long lazy = 0;
        int left_child = -1;
        int right_child = -1;
    };

    long long L, R;
    vector<Node> tree;

    DynamicLazySegmentTree(long long L, long long R, int reserve_nodes = 0) {
        this->L = L;
        this->R = R;
        if (reserve_nodes > 0) tree.reserve(reserve_nodes);
        tree.push_back(Node());
    }

    int new_node() {
        tree.push_back(Node());
        return (int)tree.size()-1;
    }

    int ensure_left_child(int node) {
        if (tree[node].left_child == -1) {
            int id = new_node();
            tree[node].left_child = id;
        }

        return tree[node].left_child;
    }

    int ensure_right_child(int node) {
        if (tree[node].right_child == -1) {
            int id = new_node();
            tree[node].right_child = id;
        }

        return tree[node].right_child;
    }

    long long get_sum(int node) const {
        if (node == -1) return 0;
        return tree[node].sum;
    }

    void apply(int node, long long left, long long right, long long value) {
        tree[node].sum += (right - left + 1LL) * value;
        tree[node].lazy += value;
    }

    void push(int node, long long left, long long right) {
        if (tree[node].lazy == 0 || left == right) return;

        long long mid = left + (right - left) / 2;

        int lc = ensure_left_child(node);
        int rc = ensure_right_child(node);

        apply(lc, left, mid, tree[node].lazy);
        apply(rc, mid + 1, right, tree[node].lazy);

        tree[node].lazy = 0;
    }

    void pull(int node) {
        tree[node].sum = get_sum(tree[node].left_child) +
            get_sum(tree[node].right_child);
    }

    void add(long long l, long long r, long long value) {
        if (l > r) return;
        add(0, L, R, l, r, value);
    }

    void add(int node, long long left, long long right, long long ql, long long qr, long long value) {
        if (qr < left || right < ql) return;

        if (ql <= left && right <= qr) {
            apply(node, left, right, value);
        } else {
            push(node, left, right);
            long long mid = left + (right - left) / 2;

            if (ql <= mid) {
                ensure_left_child(node);
                add(tree[node].left_child, left, mid, ql, qr, value);
            }

            if (qr > mid) {
                ensure_right_child(node);
                add(tree[node].right_child, mid + 1, right, ql, qr, value);
            }

            pull(node);
        }
    }

    long long query(long long l, long long r) {
        if (l > r) return 0;
        return query(0, L, R, l, r);
    }

    long long query(int node, long long left, long long right, long long ql, long long qr) {
        if (node == -1 || qr < left || right < ql) return 0;

        if (ql <= left && right <= qr) {
            return tree[node].sum;
        }

        push(node, left, right);
        long long res = 0;
        long long mid = left + (right - left) / 2;
        if (ql <= mid) res += query(tree[node].left_child, left, mid, ql, qr);
        if (qr > mid) res += query(tree[node].right_child, mid + 1, right, ql, qr);
        return res;
    }
};