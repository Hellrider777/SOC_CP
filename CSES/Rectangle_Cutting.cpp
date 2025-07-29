#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 500;
int dp[MAX + 1][MAX + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int a = 1; a <= MAX; ++a)
    {
        for (int b = 1; b <= MAX; ++b)
        {
            if (a == b)
            {
                dp[a][b] = 0; // No cuts needed if already a square
            }
            else
            {
                dp[a][b] = 1e9; // Initialize to large value

                // Try vertical cuts
                for (int i = 1; i < a; ++i)
                {
                    dp[a][b] = min(dp[a][b], dp[i][b] + dp[a - i][b] + 1);
                }

                // Try horizontal cuts
                for (int j = 1; j < b; ++j)
                {
                    dp[a][b] = min(dp[a][b], dp[a][j] + dp[a][b - j] + 1);
                }
            }
        }
    }

    int a, b;
    cin >> a >> b;
    cout << dp[a][b] << '\n';

    return 0;
}
