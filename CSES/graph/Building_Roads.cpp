#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

void dfs(int k, vector<vector<int>> &vec, vector<int> &dp)
{

    if (dp[k] == 0)
    {
        dp[k] = 1;
        for (auto i : vec[k])
        {
            dfs(i, vec, dp);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec;
    for (int i = 0; i < m; i++)
    {
        vector<int> adj(2, 0);
        cin >> adj[0] >> adj[1];
        vec.push_back(adj);
    }
    vector<vector<int>> adj_list;
    for (int i = 0; i <= n; i++)
    {
        adj_list.push_back({i});
    }
    for (auto j : vec)
    {
        adj_list[j[0]].push_back(j[1]);
        adj_list[j[1]].push_back(j[0]);
    }
    vector<vector<int>> ans;
    vector<int> dp(n + 1, 0);
    dfs(1, adj_list, dp);
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == 0)
        {
            ans.push_back({1, i});
            dfs(i, adj_list, dp);
        }
    }
    cout << ans.size();
    for (auto l : ans)
    {
        cout << endl;
        cout << l[0] << " " << l[1];
    }
}