#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll recur(ll x, ll y, vector<vector<ll>> &grid, vector<vector<ll>> &dp, ll n)
{
    if (x < 0 || y < 0 || x >= n || y >= n)
        return 0;
    if (grid[x][y] == 1)
        return 0;
    if (x == 0 && y == 0)
        return 1;
    if (dp[x][y] != -1)
        return dp[x][y];
    ll res = 0;
    res = (recur(x, y - 1, grid, dp, n) + recur(x - 1, y, grid, dp, n)) % MOD;
    dp[x][y] = res;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<vector<ll>> grid;
    for (ll i = 0; i < n; i++)
    {
        string l;
        cin >> l;
        vector<ll> row(n);
        for (ll j = 0; j < n; j++)
        {
            row[j] = (l[j] == '.') ? 0 : 1;
        }
        grid.push_back(row);
    }
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    cout << recur(n - 1, n - 1, grid, dp, n) << "\n";
}