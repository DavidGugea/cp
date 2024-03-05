#include <bits/stdc++.h>
using namespace std;

// euler totient functions => calculate the number of coprime numbers to n in [1, n) in O(sqrt(n))
int euler_totient_function(int n) {
    int result = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;

            result -= result / i;
        }
    }

    if (n > 1)
        result -= result / n;

    return result;
}