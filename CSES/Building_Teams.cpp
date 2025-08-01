#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> team(n + 1, 0); // 0 = unassigned, 1 or 2 = team number

    // Build adjacency list
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Try BFS for each component
    for (int i = 1; i <= n; ++i)
    {
        if (team[i] == 0)
        {
            queue<int> q;
            q.push(i);
            team[i] = 1;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node])
                {
                    if (team[neighbor] == 0)
                    {
                        team[neighbor] = 3 - team[node]; // alternate between 1 and 2
                        q.push(neighbor);
                    }
                    else if (team[neighbor] == team[node])
                    {
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                }
            }
        }
    }

    // Output result
    for (int i = 1; i <= n; ++i)
    {
        cout << team[i] << " ";
    }
    cout << "\n";

    return 0;
}
