#include <bits/stdc++.h>
using namespace std;

constexpr int N = 20;                                                   // Grid size
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // Movement directions
int n, m;                                                               // Grid dimensions
char grid[N][N];                                                        // Input grid
bool visited[N][N];                                                     // Visited flag
int dis[N][N];                                                          // Distance from source

inline bool is_valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(int start_i, int start_j)
{
    queue<pair<int, int>> q;
    q.push({start_i, start_j});
    visited[start_i][start_j] = true;
    dis[start_i][start_j] = 0;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (const auto &dir : directions)
        {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (is_valid(nx, ny) && !visited[nx][ny])
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
                dis[nx][ny] = dis[x][y] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;

    memset(visited, false, sizeof(visited));
    memset(dis, -1, sizeof(dis));

    bfs(si, sj);

    cout << dis[2][3] << endl;
    return 0;
}
