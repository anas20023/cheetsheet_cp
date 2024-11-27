#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll INF = INT_MAX; // Defining infinity as a large number
vector<vector<ll>> adj; // Global adjacency matrix

// Function to perform the Floyd-Warshall algorithm
void floydWarshall(int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Ensure no overflow: Only update if adj[i][k] and adj[k][j] are not infinity
                if (adj[i][k] != INF && adj[k][j] != INF && adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
}

int main()
{
    ll n, e;
    cin >> n >> e;

    // Resize the global adjacency matrix based on number of nodes
    adj.resize(n, vector<ll>(n, INF));

    // Initialize the adjacency matrix
    for (int i = 0; i < n; i++)
    {
        adj[i][i] = 0; // Distance from a node to itself is 0
    }

    // Reading the edges and updating the adjacency matrix
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        // Ensure that the edge values are within bounds
        if (a >= 0 && a < n && b >= 0 && b < n)
        {
            adj[a][b] = c;
        }
        else
        {
            cout << "Invalid edge input" << endl;
            return 1;
        }
    }

    // Call the Floyd-Warshall algorithm
    floydWarshall(n);

    // Cycle detection: Check if any diagonal element is negative
    for (int i = 0; i < n; i++)
    {
        if (adj[i][i] < 0)
        {
            cout << "Cycle detected" << endl;
            return 0;
        }
    }

    // Print the final shortest distance matrix
    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == INF)
                cout << "INF ";
            else
                cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
