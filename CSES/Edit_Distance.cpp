#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int editDistance(const string &s1, const string &s2)
{
    int n = (int)s1.size();
    int m = (int)s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base cases
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    // DP computation
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                dp[i][j] = 1 + min({
                                   dp[i - 1][j],    // delete s1[i-1]
                                   dp[i][j - 1],    // insert s2[j-1]
                                   dp[i - 1][j - 1] // replace s1[i-1] with s2[j-1]
                               });
            }
        }
    }

    return dp[n][m];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << editDistance(s1, s2) << "\n";

    return 0;
}
