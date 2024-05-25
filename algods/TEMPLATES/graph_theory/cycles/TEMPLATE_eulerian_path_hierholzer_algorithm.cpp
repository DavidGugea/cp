#include <bits/stdc++.h>
using namespace std;

int n;
int edgeCount;
vector<int> in, out, path;
vector<vector<int>> graph;

void setUp() {
    in.assign(n, 0);
    out.assign(n, 0);

    edgeCount = 0;

    for (int from = 0; from < n; ++from) {
        for (int to : graph[from]) {
            in[to]++;
            out[from]++;
            edgeCount++;
        }
    }
}

bool graphHasEulerianPath() {
    if (edgeCount == 0) return false;
    int startNodes = 0, endNodes = 0;
    for (int i = 0; i < n; ++i) {
        if (out[i] - in[i] > 1 || in[i] - out[i] > 1)
            return false;
        else if (out[i] - in[i] == 1) ++startNodes;
        else if (in[i] - out[i] == 1) ++endNodes;
    }

    return (endNodes == 0 && startNodes == 0) || (endNodes == 1 && startNodes == 1);
}

int findStartNode() {
    int start = 0;

    for (int i = 0; i < n; ++i) {
        // unique starting node
        if (out[i] - in[i] == 1)
            return i;

        // start at a node with an outgoing edge
        if (out[i]  > 0) start = i;
    }

    return start;
}

void dfs(int at) {
    while (out[at] != 0) {
        int next = graph[at][--out[at]];
        dfs(next);
    }

    path.push_back(at);
}

void hierholzer() {
    setUp();

    if (!graphHasEulerianPath()) return;
    dfs(findStartNode());

    if (path.size() != edgeCount + 1) return;
}