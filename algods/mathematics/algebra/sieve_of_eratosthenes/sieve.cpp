#include <bits/stdc++.h>
using namespace std;

void sieve() {
    int n;

    vector<bool> is_prime(n+1, true); // from 0 to n
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i*i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

void sieve_till_root() {
    int n;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}