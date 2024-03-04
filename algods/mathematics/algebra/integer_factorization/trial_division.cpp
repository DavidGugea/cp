#include <bits/stdc++.h>
using namespace std;

// time complexity: O(sqrt(n))
vector<long long> trial_division1(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; ++d) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }

    if (n > 1)
        factorization.push_back(n);

    return factorization;
}

vector<long long> trial_division2(long long n) {
    vector<long long> factorization;
    while (n % 2 == 0) {
        factorization.push_back(2);
        n /= 2;
    }

    for (long long d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }

    if (n > 1) 
        factorization.push_back(n);

    return factorization;
}

vector<long long> trial_division3(long long n) {
    vector<long long> factorization;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }

    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
        if (i == 8)
            i = 0;
    }

    if (n > 1)
        factorization.push_back(n);

    return factorization;
}

// precomputed primes
vector<long long> trial_division4(long long n) {
    vector<long long> primes; // list of all the primes up to sqrt(n)
    vector<long long> factorization;
    for (long long d : primes) {
        if (d * d > n)
            break;

        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }

    if (n > 1)
        factorization.push_back(n);

    return factorization;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<long long> res = trial_division2(n);
    for (long long i : res)
        cout << i << " ";
    cout << "\n";

    return 0;
}