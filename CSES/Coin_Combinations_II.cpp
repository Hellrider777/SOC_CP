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
    for (ll i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = vec[i]; j <= x; j++)
        {
            dp[j] += dp[j - vec[i]] % MOD;
        }
    }
    cout << dp[x] % MOD;
}