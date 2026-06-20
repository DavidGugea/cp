#include <bits/stdc++.h>
using namespace std;

// pre C++20
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

// Sparse Table for RMQ (or other idempotent functions)
// Static range queries, no updates allowed after build.
// Build: O(n log n)
// Query: O(1)
// Space: O(n log n)
struct SparseTable {
    int n, p;
    vector<vector<int>> st;      // st[i][j] -> [j, j + 2^i)

    SparseTable(const vector<int>& a) {
        n = a.size();

        p = log2_floor(n);
        st.assign(p + 1, vector<int>(n));

        for (int j = 0; j < n; ++j) {
            st[0][j] = a[j];
        }

        for (int i = 1; i <= p; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                st[i][j] = min(
                    st[i - 1][j],
                    st[i - 1][j + (1 << (i - 1))]
                );
            }
        }
    }

    int query(int l, int r) {
        int len = r - l + 1;
        p = log2_floor(n);

        return min(
            st[p][l],
            st[p][r - (1 << p) + 1]
        );
    }
};