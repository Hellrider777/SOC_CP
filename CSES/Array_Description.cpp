#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    vector<vector<int>> dp(n, vector<int>(m + 2, 0)); // using m+2 to avoid boundary issues

    // Base case
    if (vec[0] == 0)
    {
        for (int i = 1; i <= m; i++)
            dp[0][i] = 1;
    }
    else
    {
        dp[0][vec[0]] = 1;
    }

    // DP transition
    for (int i = 1; i < n; i++)
    {
        if (vec[i] == 0)
        {
            for (int v = 1; v <= m; v++)
            {
                dp[i][v] = ((ll)dp[i - 1][v] + dp[i - 1][v - 1] + dp[i - 1][v + 1]) % MOD;
            }
        }
        else
        {
            int v = vec[i];
            dp[i][v] = ((ll)dp[i - 1][v] + dp[i - 1][v - 1] + dp[i - 1][v + 1]) % MOD;
        }
    }

    // Final answer
    int result = 0;
    for (int v = 1; v <= m; v++)
    {
        result = (result + dp[n - 1][v]) % MOD;
    }
    cout << result << '\n';
}
