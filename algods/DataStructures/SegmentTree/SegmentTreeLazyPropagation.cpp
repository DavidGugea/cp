#include <bits/stdc++.h>
using namespace std;

const int N = 1e9;

struct Segment {
    int sum, lazy;
} segm_tree[2 * N];

void propagate(int node, int left, int right) {
    // node: index of node in ST
    // left, right: interval of corresponding node in ST
    // calculate the sum of the current node by adding lazy to all elements from left to right
    segm_tree[node].sum += (right - left + 1) * segm_tree[node].lazy;

    // pass the lazy to node's sons if it is not a leaf
    if (left < right) {
        segm_tree[2 * node + 1].lazy += segm_tree[node].lazy;
        segm_tree[2 * node + 2].lazy += segm_tree[node].lazy;
    }

    // since the node is now up-to-date, lazy becomes 0
    segm_tree[node].lazy = 0;
}

void update(int node, int left, int right, int x, int y, int value) {
    // left, right: segment
    // x, y: update query
    // add <value> to a[x...y]
    propagate(node, left, right);
    if (x <= left && right <= y) {
        segm_tree[node].lazy += value;
    } else {
        int middle = left + (right - left) / 2;

        if (x <= middle) {
            update(2 * node + 1, left, middle, x, y, value);
        }

        if (y >= middle) {
            update(2 * node + 2, middle + 1, right, x, y, value);
        }

        // call propagate on the children. We use them to update the current node, so they must be up to date
        propagate(2 * node + 1, left, middle);
        propagate(2 * node + 2, middle + 1, right);
        segm_tree[node].sum = segm_tree[2 * node + 1].sum + segm_tree[2 * node + 2].sum;
    }
}

int main() {

    return 0;
}