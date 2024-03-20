#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b, cost;
};

vector<int> bellman_ford() {
    int n, m, v;
    vector<Edge> edges;
    const int INF = 1e9+9;

    vector<int> d(n, INF);
    d[v] = 0;
    vector<int> p(n, -1); // store the predecessor for each node in order to restore the shortest paths
    bool possible_negative_cycles = true;

    for (int i = 0; i < n; ++i) {
        bool any = false;

        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                any = true;
            }
        }

        // if the relaxation hasn't changed the distance to any edge, there's no point in doing other iterations. there's also no possiblity of having any negative cycles. stop here.
        if (!any) {
            possible_negative_cycles = false;
            break;
        }
    }

    // check for negative cycles - one more iteration
    if (possible_negative_cycles) {
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = -INF;
            }
        }
    }

    return d;
}