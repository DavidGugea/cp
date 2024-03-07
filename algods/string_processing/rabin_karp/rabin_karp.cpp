#include <bits/stdc++.h>
using namespace std;

// s pattern | t text
// O(|s| + |t|)
// determine if the pattern appears in the text and if it does, enumerate all its occurrences
vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31;
    const int m = 1e9+9;
    int S = s.size(), T = t.size();

    // precompute pow values
    vector<long long> p_pow(max(S, T));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); ++i)
        p_pow[i] = (p_pow[i-1] % p) % m;

    // compute hash of t substrings and hash of the pattern
    vector<long long> h(T+1, 0);
    for (int i = 0; i < T; ++i)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;

    long long h_s = 0;
    for (int i = 0; i < S; ++i)
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

    // find occurrences of the pattern inside the text and return them
    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; --i) {
        // compute hash of the current substring
        long long cur_h = (h[i+S] + m - h[i]) % m;

        // compare current hash with the hash of the pattern
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }

    return occurrences;
}