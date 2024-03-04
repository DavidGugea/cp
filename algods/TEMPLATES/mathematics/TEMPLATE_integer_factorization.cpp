#include <bits/stdc++.h>
using namespace std;

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

// division by prime numbers (up to sqrt(N))
vector<long long> trial_division_prime_numbers(long long n) {
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