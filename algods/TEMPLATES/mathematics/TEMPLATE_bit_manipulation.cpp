#include <bits/stdc++.h>
using namespace std;

bool is_set(unsigned int number, int x) {
    // check if a bit is set
    return (number >> x) & 1;
}

bool isDivisibleByPowerOf2(int n, int k) {
    // check if the nubmer is divisible by a power of 2
    int powerOf2 = 1 << k;
    return (n & (powerOf2-1)) == 0;
}

bool isPowerOfTwo(unsigned int n) {
    // check if an integer is a power of 2
    return n && !(n & (n-1));
}

int countSetBits(int n) {
    // Brian Kerninghan's Algorithm -> count set bits
    int count = 0;
    while (n) {
        n = n & (n - 1);
        ++count;
    }

    return count;
}

void main() {
    int n, x;

    // set the xth bit in the number n
    n | (1 << x);

    // flip the xth bit in the number n
    n ^ (1 << x);

    // clear the xth bit in the number n
    n & ~(1 << x);

    // clear the right-most set bit
    n & (n-1);

    // clear all trailing ones 0011 0111 -> 0011 0000
    n & (n + 1);

    // sets the last cleared bit 0011 0101 -> 0011 0111
    n | (n + 1);

    // extracts the last set bit -> 0011 0100 -> 0000 0100
    n & -n;
}