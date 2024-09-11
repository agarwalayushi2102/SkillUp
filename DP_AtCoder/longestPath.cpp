#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }

    // Topological sort using Kahn's algorithm (BFS)
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Longest path using DP
    vector<int> dist(n + 1, 0); // Use 0 instead of INT_MIN

    for (int u : topo_order) {
        for (int v : adj[u]) {
            dist[v] = max(dist[v], dist[u] + 1);
        }
    }

    // Find the maximum distance
    int mxPath = 0;
    for (int i = 1; i <= n; i++) {
        mxPath = max(mxPath, dist[i]);
    }

    cout << mxPath << endl;

    return 0;
}
