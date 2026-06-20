#include <bits/stdc++.h>
using namespace std;

// pre C++20
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

struct SparseTable {
    int n, p;
    vector<vector<int>> st; // (i,j) => [j, j + 2^i)

    SparseTable(const vector<int>& a) {
        n = a.size();

        p = log2_floor(n);
        st.assign(p + 1, vector<int>(n));
        for (int j = 0; j < n; ++j) st[0][j] = a[j];

        for (int i = 1; i <= p; ++i) {
            for (int j = 0; j + (1<<i) <= n; ++j) {
                st[i][j] = min(
                    st[i-1][j],
                    st[i-1][j + (1 << (i-1))]
                );
            }
        }
    }

    int query(int l, int r) {
        int len = r - l + 1;
        int p = log2_floor(len);

        return min(
            st[p][l],
            st[p][r - (1 << p) + 1]
        );
    }
};

int main() {
    vector<int> a = {5, 2, 7, 3, 6, 1, 4};

    SparseTable rmq(a);

    cout << rmq.query(0, 6) << '\n'; // 1
    cout << rmq.query(0, 2) << '\n'; // min(5,2,7) = 2
    cout << rmq.query(2, 4) << '\n'; // min(7,3,6) = 3
    cout << rmq.query(3, 5) << '\n'; // min(3,6,1) = 1
    cout << rmq.query(5, 5) << '\n'; // 1


    return 0;
}