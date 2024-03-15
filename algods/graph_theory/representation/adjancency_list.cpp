#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < k; ++i) {
        int a, b; cin >> a >> b;
        auto it = m.find(a);

        if (it == m.end()) {
            vector<int> na;
            na.push_back(b);
            m.insert(make_pair(a, na));
        } else {
            m[a].push_back(b);
        }
    }

    for (pair<int, vector<int>> p : m) {
        cout << p.first << ": ";
        for (int i : p.second) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}