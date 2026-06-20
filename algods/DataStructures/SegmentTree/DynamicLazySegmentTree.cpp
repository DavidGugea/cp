#include <bits/stdc++.h>
using namespace std;

struct DynamicLazySegmentTree {
    struct Node {
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

        tree.push_back(Node()); // root is node 0
    }

    int new_node() {
        tree.push_back(Node());
        return (int)tree.size()-1;
    }

    long long get_sum(int node) const {
        if (node== -1) return 0;
        return tree[node].sum;
    }

    void apply(int node, long long left, long long right, long long value) {
        tree[node].sum += (right - left + 1LL) * value;
        tree[node].lazy += value;
    }

    void push(int node, long long left, long long right) {
        if (tree[node].lazy == 0 || left == right) return;

        long long mid = left + (right - left) / 2;

        if (tree[node].left_child == -1) tree[node].left_child = new_node();
        if (tree[node].right_child == -1) tree[node].right_child = new_node();

        int lc = tree[node].left_child;
        int rc = tree[node].right_child;

        apply(lc, left, mid, tree[node].lazy);
        apply(rc, mid + 1, right, tree[node].lazy);

        tree[node].lazy = 0;
    }

    void pull(int node) {
        tree[node].sum = 
            get_sum(tree[node].left_child) +
            get_sum(tree[node].right_child);
    }

    void add(long long l, long long r, long long value) {
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
                if (tree[node].left_child == -1) tree[node].left_child = new_node();
                add(tree[node].left_child, left, mid, ql, qr, value);
            } else {
                if (tree[node].right_child == -1) tree[node].right_child= new_node();
                add(tree[node].right_child, mid + 1, right, ql, qr, value);
            }
            pull(node);
        }
    }

    long long query(long long l, long long r) {
        return query(0, L, R, l, r);
    }

    long long query(int node, long long left, long long right, long long ql, long long qr) {
        if (node == -1 || qr < left || right < ql) return 0;

        if (ql <= left && right <= qr) {
            return tree[node].sum;
        } else {
            push(node, left, right);
            long long mid = left + (right - left) / 2;
            long long res = 0;
            if (ql <= mid) res += query(tree[node].left_child, left, mid, ql, qr);
            if (ql > mid) res += query(tree[node].right_child, mid + 1, right, ql, qr);
            return res;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Coordinate universe: [0, 1e9]
    DynamicLazySegmentTree st(0, 1000000000LL);

    st.add(10, 20, 5);
    // positions 10..20 receive +5

    st.add(15, 100, 2);
    // positions 15..100 receive +2

    cout << st.query(10, 10) << '\n';   // 5
    cout << st.query(15, 20) << '\n';   // 42 = 6 positions * 7
    cout << st.query(21, 100) << '\n';  // 160 = 80 positions * 2
    cout << st.query(0, 9) << '\n';     // 0

    return 0;
}