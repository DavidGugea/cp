#include <bits/stdc++.h>
using namespace std;

bool trivial_prime(long long x) {
    for (long long i = 2; i*i < x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

