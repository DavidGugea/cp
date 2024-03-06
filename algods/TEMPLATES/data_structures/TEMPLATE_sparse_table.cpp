#include <bits/stdc++.h>
using namespace std;

int log2_floor(unsigned long long i)
{
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

// WORKS ONLY ON IMMTABLE ARRAYS WITH OVERLAP FRIENDLY FUNCTIONS
// time complexity: O(1)
// current example: min range queries
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // dp[i][j] = f(dp[i-1][j], dp[i-1][j+2^(i-1)])
    // q(l, r) = f(dp[p][l], dp[p][r-k+1]) where p = log2(r-l+1) && k=2^p=(1<<p)

    // initialize the first row of the sparse table (original array)
    int n; cin >> n;
    int dpr = log2_floor(n) + 1;
    vector<vector<int>> dp(dpr, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        cin >> dp[0][i];
    }

    // construct the table
    for (int i = 1; i < n; ++i)
        for (int j = 0; (j + (1 << i)) <= n; ++j)
            dp[i][j] = min(dp[i-1][j], dp[i-1][j+1<<(i-1)]);

    // answer queries
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;

        int p = log2_floor(r - l + 1);
        int k = 1<<p;

        int res = min(dp[p][l], dp[p][r-k+1]);
        cout << res << "\n";
    }

    return 0;
}