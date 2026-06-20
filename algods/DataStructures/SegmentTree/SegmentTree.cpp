#include <bits/stdc++.h>
using namespace std;

vector<int> segm_tree;
vector<int> a;
const int INF = 1e9;

void recalculate(int node) {
    segm_tree[node] = max(segm_tree[2 * node + 1], segm_tree[2 * node + 2]);
}

void build(int node, int left, int right) {
    // node: index of current node inside the segment tree
    // left, right: range of current node inside the segment tree
    if (left == right) {
        segm_tree[node] = a[left];
    } else {
        int middle = left + (right - left) / 2;
        build(node * 2 + 1, left, middle);
        build(node * 2 + 2, middle + 1, right);
        recalculate(node);
    }
}

// update: a[x] = y;
void update(int node, int left, int right, int x, int y) {
    // node: index of current node inside the segment tree
    // left, right: range of the current node
    // a[x] = y;
    if (left == right) {
        segm_tree[node] = y;
    } else {
        int middle = left + (right - left) / 2;

        if (x <= middle) update(2 * node + 1, left, middle, x, y);
        else update(2 * node + 2, middle + 1, right, x, y);

        recalculate(node);
    }
}

// query on segment [x, y]
int query(int node, int left, int right, int x, int y) {
    if (x <= left && right <= y) {
        // the whole segment sits inside the target query => return the value of the segment
        return segm_tree[node];
    } else {
        // the current segment doesn't sit entirely inside the target query. We need to split the current segment using the answers of its children
        // for that recurse through its children through the segment tree and build the answer that way
        int res = -INF;

        int middle = left + (right - left) / 2;

        if (x <= middle) res = max(res, query(2 * node + 1, left, middle, x, y));
        if (y > middle) res = max(res, query(2 * node + 2, middle + 1, right, x, y));

        return res;
    }
}

int main() {
    a = {5, 2, 7, 3, 6};

    int n = a.size();
    segm_tree.assign(4 * n, -INF);

    build(0, 0, n - 1);

    cout << query(0, 0, n - 1, 0, 4) << '\n'; // 7
    cout << query(0, 0, n - 1, 1, 3) << '\n'; // 7

    update(0, 0, n - 1, 3, 10); // a[3] = 10

    cout << query(0, 0, n - 1, 1, 3) << '\n'; // 10
    cout << query(0, 0, n - 1, 0, 4) << '\n'; // 10

    return 0;
}