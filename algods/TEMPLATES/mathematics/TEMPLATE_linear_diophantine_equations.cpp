#include <bits/stdc++.h>
using namespace std;


// ax + by = c
// if c | gcd(a, b) => there exists a solution, otherwise there's no solution

int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

bool linear_diophantine_equation(int a, int b, int c, int& x0, int& y0) {
    int g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) { 
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;

    return true;
}