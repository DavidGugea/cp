#include <bits/stdc++.h>
using namespace std;

// Sqrt Decomposition - Point updates, Range sum queries - 0-indexed, query range is inclusive: [l, r]
// Build:  O(n)
// Update: O(1)
// Query:  O(sqrt(n))
// Space:  O(n)
struct SqrtDecomposition {
    int n;
    int block_size;
    int block_count;

    vector<long long> a;
    vector<long long> block_sum;

    SqrtDecomposition(const vector<long long>& arr) {
        a = arr;
        n = arr.size();

        block_size = (int)sqrt(n) + 1;
        block_count = (n + block_size - 1) / block_size;

        block_sum.assign(block_count, 0);
        for (int i = 0; i < n; ++i) {
            block_sum[i / block_size] += a[i];
        }
    }

    void add(int idx, long long delta) {
        a[idx] += delta;
        block_sum[idx / block_size] += delta;
    }

    long long query(int l, int r) const {
        long long res = 0;

        int left_block = l / block_size;
        int right_block = r / block_size;

        if (left_block == right_block) {
            for (int i = l; i <= r; ++i) {
                res += a[i];
            }
        } else {
            int left_block_end = min(n - 1, (left_block + 1) * block_size -1);
            int right_block_end = right_block * block_size;

            for (int i = l; i <= left_block_end; ++i) res += a[i];
            for (int i = right_block_end; i <= r; ++i) res += a[i];
            for (int b = left_block + 1; b <= right_block - 1; ++b) res += block_sum[b];
        }

        return res;
    }
};