#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(log N)
long long binpow(long long a, long long b) {
    long long res = 1;

    while (b > 0) {
        if (b & 1)
            res *= a;

        a *= a;
        b >>= 1;
    }

    return res;
}