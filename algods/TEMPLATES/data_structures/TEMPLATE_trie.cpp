#include <bits/stdc++.h>
using namespace std;

// Trie for lowercase English strings 'a' to 'z'
// Operations:
//   insert(s):        O(|s|)
//   erase(s):         O(|s|)  removes one occurrence if it exists
//   count_word(s):    O(|s|)  number of times exact string s was inserted
//   count_prefix(p):  O(|p|)  number of inserted strings starting with p
//   contains(s):      O(|s|)
//   starts_with(p):   O(|p|)
//
// Space: O(number of created trie nodes * ALPHABET)
struct Trie {
    static constexpr int ALPHABET = 26;

    struct Node {
        array<int, ALPHABET> child;
        int prefix_count = 0;
        int end_count = 0;

        Node() {
            child.fill(-1);
        }
    };

    vector<Node> trie;

    Trie(int reserve_nodes = 0) {
        if (reserve_nodes > 0) trie.reserve(reserve_nodes);
        trie.push_back(Node());
    }

    int new_node() {
        trie.push_back(Node());
        return (int)trie.size() - 1;
    }

    int get_id(char ch) const {
        return ch - 'a';
    }

    void insert(const string& s) {
        int node = 0;
        trie[node].prefix_count++;

        for (char ch : s) {
            int c = get_id(ch);
            if (trie[node].child[c] == -1) {
                int id = new_node();
                trie[node].child[c] = id;
            }
            node = trie[node].child[c];
            trie[node].prefix_count++;
        }

        trie[node].end_count++;
    }

    int count_word(const string& s) const {
        int node = 0;

        for (char ch : s) {
            int c = get_id(ch);
            if (trie[node].child[c] == -1) return 0;
            node = trie[node].child[c];
        }

        return trie[node].end_count;
    }

    int count_prefix(const string& s) const {
        int node = 0;

        for (char ch : s) {
            int c = get_id(ch);
            if (trie[node].child[c] == -1) return 0;
            node = trie[node].child[c];
        }

        return trie[node].prefix_count;
    }

    bool contains(const string& s) const {
        return count_word(s) > 0;
    }

    bool starts_with(const string& s) const {
        return count_prefix(s) > 0;
    }

    bool erase(const string& s) {
        if (count_word(s) == 0) return false;
        int node = 0;
        trie[node].prefix_count--;

        for (char ch : s) {
            int c = get_id(ch);
            node = trie[node].child[c];
            trie[node].prefix_count--;
        }

        trie[node].end_count--;
        return true;
    }
};