#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;
    vector<ll> vec(n);
    for (ll i = 0; i < n; ++i)
        cin >> vec[i];

    vector<ll> dp(x + 1, 0);
    dp[0] = 1;

    // This loop gives number of permutations (order matters)
    for (ll i = 1; i <= x; ++i)
    {
        for (ll coin : vec)
        {
            if (i - coin >= 0)
            {
                dp[i] = (dp[i] + dp[i - coin]) % MOD;
            }
        }
    }

    cout << dp[x] << '\n';
}
