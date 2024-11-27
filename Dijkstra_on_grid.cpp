#include<bits/stdc++.h>
using namespace std;

vector<int> dirX = {-1, 1, 0, 0};
vector<int> dirY = {0, 0, -1, 1};

void dijkstra(int n, int m, vector<vector<int>>& grid, pair<int, int> src) {
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    dist[src.first][src.second] = grid[src.first][src.second];
    pq.push({grid[src.first][src.second], src.first, src.second});

    while (!pq.empty()) {
        int d, x, y;
        tie(d, x, y) = pq.top();
        pq.pop();

        if (d > dist[x][y]) continue;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dirX[i], ny = y + dirY[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                int newDist = dist[x][y] + grid[nx][ny];
                if (newDist < dist[nx][ny]) {
                    dist[nx][ny] = newDist;
                    parent[nx][ny] = {x, y};
                    pq.push({newDist, nx, ny});
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dist[i][j] == INT_MAX) {
                cout << "Node (" << i << ", " << j << ") is unreachable\n";
            } else {
                cout << "Distance to (" << i << ", " << j << "): " << dist[i][j] << "\nPath: ";
                stack<pair<int, int>> path;
                for (pair<int, int> cur = {i, j}; cur != make_pair(-1, -1); cur = parent[cur.first][cur.second]) path.push(cur);
                while (!path.empty()) {
                    auto [x, y] = path.top();
                    cout << "(" << x << ", " << y << ")";
                    path.pop();
                    if (!path.empty()) cout << " -> ";
                }
                cout << "\n";
            }
        }
    }
}

int main() {
    int n, m;
    pair<int, int> src;
    cin >> n >> m >> src.first >> src.second;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];
    dijkstra(n, m, grid, src);
    return 0;
}
