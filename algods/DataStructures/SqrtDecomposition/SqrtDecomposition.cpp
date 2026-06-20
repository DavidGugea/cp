#include <bits/stdc++.h>
using namespace std;

struct SqrtDecomposition {
    int n;
    int block_size;
    int block_count;

    vector<long long> a;
    vector<long long> block_sum;

    SqrtDecomposition(const vector<long long>& arr) {
        a = arr;
        n = (int)a.size();

        block_size = (int)sqrt(n)+1;
        block_count = (n + block_size - 1) / block_size;
        block_sum.assign(block_count, 0);

        for (int i = 0; i < n; ++i) 
            block_sum[i / block_size] += a[i];
    }

    void add(int idx, long long delta) {
        a[idx] += delta;
        block_sum[idx/block_size] += delta;
    }

    long long query(int l, int r) const {
        long long res = 0;

        int left_block = l / block_size;
        int right_block = r / block_size;

        if (left_block == right_block) {
            for (int i = l; i <= r; ++i) res += a[i];
        } else {
            int left_block_end = min(n-1, (left_block + 1) * block_size - 1);
            int right_block_start = right_block * block_size;

            for (int i = l; i <= left_block_end; ++i) res += a[i];
            for (int i = right_block_start; i <= r; ++i) res += a[i];
            for (int b = left_block + 1; b <= right_block - 1; ++b) res += block_sum[b];
        }

        return res;
    }
};

int main() {
    vector<long long> a = {5, 2, 7, 3, 6, 1, 4, 8, 9, 10};
    SqrtDecomposition sd(a);
    cout << sd.query(2, 8) << '\n'; // 38
    sd.add(4, 10); // a[4] += 10
    cout << sd.query(2, 8) << '\n'; // 48

    return 0;
}