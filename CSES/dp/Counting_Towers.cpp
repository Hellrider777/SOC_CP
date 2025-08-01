#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> queries(t);
    int max_n = 0;
    for (int i = 0; i < t; ++i)
    {
        cin >> queries[i];
        max_n = max(max_n, queries[i]);
    }

    vector<int> dp(max_n + 2);
    dp[1] = 2;
    dp[2] = 8;

    for (int i = 3; i <= max_n; ++i)
    {
        dp[i] = (4LL * dp[i - 1] % MOD - dp[i - 2] + MOD) % MOD;
    }

    for (int n : queries)
    {
        cout << dp[n] << '\n';
    }

    return 0;
}
