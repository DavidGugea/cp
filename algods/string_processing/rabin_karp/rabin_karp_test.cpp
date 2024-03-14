#include <bits/stdc++.h>
using namespace std;

vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31;
    const int m = 1e9+9;
    int S = s.size(), T = t.size();

    // precompute powers of p
    vector<long long> p_pow(max(S, T));
    p_pow[0] = 1;
    for (int i = 1; i < p_pow.size(); ++i)
        p_pow[i] = p_pow[i-1] * p % m;

    // compute the hash of the pattern
    long long pattern_hash = 0;
    for (int i = 0; i < S; ++i)
        pattern_hash = (pattern_hash + (s[i] - 'a' + 1) * p_pow[i]) % m;

    // compare hashes of substrings using the rolling hash technique and find occurrences
    vector<int> occurrences;

    // get hash of the first substring with the length of S
    long long current_pattern_hash = 0;
    for (int i = 0; i < S; ++i)
        current_pattern_hash = (current_pattern_hash + (t[i] - 'a' + 1) * p_pow[i]) % m;

    if (current_pattern_hash == pattern_hash)
        occurrences.push_back(0);

    for (int i = 1; i + S - 1 < T; ++i) {
        current_pattern_hash -= (t[i-1] - 'a' + 1);
        current_pattern_hash = (current_pattern_hash / p) % m;
        current_pattern_hash = (current_pattern_hash + (t[i+S-1] - 'a' + 1) * p_pow[S-1]) % m;

        if (current_pattern_hash == pattern_hash)
            occurrences.push_back(i);
    }

    return occurrences;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string const s = "abc";
    string const t = "abcabcabcabcabcabc";
    vector<int> occurrences = rabin_karp(s, t);
    for (int i : occurrences)
        cout << i << "\n";

    return 0;
}