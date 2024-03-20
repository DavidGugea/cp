#include <bits/stdc++.h>
using namespace std;

bool spfa(int s, vector<int>& d) {
    const int INF = 1e9+9;
    vector<vector<pair<int, int>>> adj;

    int n = adj.size();
    d.assign(n, INF);
    vector<int> cnt(n, 0); // counter used to detect negative cycles
    vector<bool> inqueue(n, false);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                // relaxation
                d[to] = d[v] + len;

                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;

                    if(cnt[to] > n)
                        return false; // negative cycles
                }
            }
        }
    }

    return true;
}