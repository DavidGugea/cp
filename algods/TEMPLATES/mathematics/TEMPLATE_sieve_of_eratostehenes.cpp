#include <bits/stdc++.h>
using namespace std;

// time complexity: O(nloglogn)
vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> p;
    for (int i = 0; i < is_prime.size(); ++i) {
        if (is_prime[i])
            p.push_back(i);
    }

    return p;
}