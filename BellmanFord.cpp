#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

const int N = 1e5 + 5;
int dis[N];

void bellmanFord(int n, vector<Edge> &EdgeList, int src)
{
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[src] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;

            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
}

int main()
{
    int n, e, src;
    cin >> n >> e >> src;

    vector<Edge> EdgeList;

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        // u--, v--;   // if input is 1-indexed
        EdgeList.push_back(Edge(u, v, c));
    }

    bellmanFord(n, EdgeList, src);

    for (int i = 0; i < n; i++)
    {
        if (dis[i] == INT_MAX)
        {
            cout << i << " -> " << "Unreachable" << endl;
        }
        else
        {
            cout << i << " -> " << dis[i] << endl;
        }
    }

    return 0;
}
