#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, 2e5);
    vector<int> parent(n + 1, -1);
    queue<int> q;

    dist[1] = 1;
    q.push(1);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node])
        {
            if (dist[neighbor] == 2e5)
            {
                dist[neighbor] = dist[node] + 1;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    if (dist[n] == 2e5)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << dist[n] << "\n";

        // To print the path (optional):
        vector<int> path;
        for (int at = n; at != -1; at = parent[at])
            path.push_back(at);
        reverse(path.begin(), path.end());

        for (int x : path)
            cout << x << " ";
        cout << "\n";
    }
}
