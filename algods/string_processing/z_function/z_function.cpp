#include <bits/stdc++.h>
using namespace std;

// aaaaa   - [0, 4, 3, 2, 1]
// aaabaab - [0, 2, 1, 0, 2, 1, 0]
// abacaba -  [0, 0, 1, 0, 3, 0, 1]
vector<int> z_function_trivial(string s) {
    int n = s.size();
    vector<int> z(n);

    for (int i = 1; i < n; ++i) {
        while (i + z[i] < n && s[z[i]] == s[i+z[i]])
            z[i]++;
    }

    return z;
}

vector<int> z_function(string s) {
    int n =  s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r) {
            z[i] = min(r-i, z[i-l]);
        }

        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            z[i]++;

        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }

    return z;
}