#include <bits/stdc++.h>
using namespace std;


// Time Complexity: O(log(min(a, b)))

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }

    return a;
}

long long gcd(long long a, long long b) {
    if (!a || !b)
        return a | b;

    unsigned long long shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}