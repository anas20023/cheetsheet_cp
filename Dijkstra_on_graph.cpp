#include<bits/stdc++.h>
using namespace std;

void dijkstra(int n, vector<pair<int, int>> adj[], int src) {
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &[v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Distance to node " << i << ": " << dist[i] << "\nPath: ";
            stack<int> path;
            for (int cur = i; cur != -1; cur = parent[cur]) path.push(cur);
            while (!path.empty()) {
                cout << path.top() << (path.size() > 1 ? " -> " : "\n");
                path.pop();
            }
        }
    }
}

int main() {
    int n, m, src;
    cin >> n >> m >> src;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        //adj[v].emplace_back(u, w); // For undirected graphs; remove for directed.
    }
    dijkstra(n, adj, src);
    return 0;
}
