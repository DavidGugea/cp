#include <bits/stdc++.h>
using namespace std;

vector<int> tree, A;

// O(N)
void build(int node, int start, int end) {
    // node -> index of the current element of the segment tree
    // start, end -> denote the interval of the current node of the segment tree

    if (start == end) {
        // leaf node will havea  single element
        tree[node] = A[start];
    } else {
        int mid = (start + end) / 2;

        // recurse on the left child
        build(2*node, start, mid);

        // recurse on the right child
        build(2*node+1,mid+1, end);

        // internal node will have the sum of both of its children
        tree[node] = tree[node*2] + tree[node*2 + 1];
    }
}

// O(log N)
void update(int node, int start, int end, int idx, int val) {
    // node: index of the current node in the segment tree
    // start, end: interval of the current node
    // idx: idx of the value in the original array that has to be updated
    // val: the value that has to be added to the element in the original array that we want to change
    if (start == end) {
        // leaf node
        A[idx] += val;
        tree[node] += val;
    } else {
        int mid = (start + end) / 2;

        if (start <= idx && idx <= mid) {
            // if idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        } else {
            // if idx is in the right child, recurse on the right child
            update(2*node + 1, mid + 1, end, idx, val);
        }

        // internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node + 1];
    }
}

// O(log N)
int query(int node, int start, int end, int l, int r) {
    // node: index of the current node in the tree
    // start, end: start and end intervals of the current node in the tree
    // l, r: left right intervals of the query

    if (r < start || end < l) {
        // range represented by a node is compeltely outside the given range
        return 0;
    }

    if (l <= start && end <= r) {
        // range represneted by a node is completely inside the given range
        return tree[node];
    }

    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int query_left_child = query(2 * node, start, mid, l, r);
    int query_right_child = query(2 * node + 1, mid + 1, end, l, r);
    return (query_left_child + query_right_child);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}