#include <bits/stdc++.h>
using namespace std;

struct Query {
    int l, r, idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<Query> queries(q);

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        queries[i] = {l, r, i};
    }

    int block_size = max(1, (int)(n/sqrt(q)));
    sort(queries.begin(), queries.end(), [&](const Query& a, const Query& b) {
        int block_a = a.l / block_size;
        int block_b = b.l / block_size;

        if (block_a != block_b) return block_a < block_b;

        // return a.r < b.r;
        return (block_a & 1) ? (a.r > b.r) : (a.r < b.r);
    });

    vector<long long> ans(q);
    long long current_answer = 0;

    /* problem specific */
    auto add = [&](int idx) {
        current_answer += a[idx];
    };

    auto remove = [&](int idx) {
        current_answer -= a[idx];
    };
    /* problem specific */

    int cur_l = 0;
    int cur_r = -1;

    for (const Query& query : queries) {
        int l = query.l;
        int r = query.r;

        while (cur_l > l) add(--cur_l);
        while (cur_r < r) add(++cur_l);
        while (cur_l < l) remove(cur_l++);
        while (cur_r > r) remove(cur_r--);

        ans[query.idx] = current_answer;
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}