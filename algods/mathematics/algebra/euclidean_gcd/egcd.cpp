#include <bits/stdc++.h>
using namespace std;

// O(log(min(a,b)))

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }

    return a;
}

int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}