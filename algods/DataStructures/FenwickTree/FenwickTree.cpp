#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<long long> bit;

    BIT(int n) : n(n), bit (n+1, 0){}
    BIT(const vector<long long>& a) : BIT((int)a.size()) {
        for (int i = 1; i <= n; ++i) {
            bit[i] += a[i-1];

            int j = i + (i & -i); // parent
            if (j <= n) bit[j] += bit[i];
        }
    }

    void add(int idx, long long delta) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += delta;
    }

    long long prefix_sum(int idx) {
        long long res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res += bit[idx];
        }
        return res;
    }

    long long query(int l, int r) {
        return prefix_sum(r) - prefix_sum(l-1);
    }
};

int main() {
    vector<long long> a = {5, 2, 7, 3, 6};
    BIT ft(a);

    cout << ft.query(1, 5) << '\n'; // 23
    cout << ft.query(2, 4) << '\n'; // 12 (2+7+3)

    ft.add(3, 10); // a[3] += 10 (1-indexed)

    cout << ft.query(1, 5) << '\n'; // 33
    cout << ft.query(2, 4) << '\n'; // 22 (2+17+3)

    return 0;
    return 0;
}