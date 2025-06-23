#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll INF = 1e9 + 7;

ll recur(ll n, vector<ll> &vec, vector<ll> &dp)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INF;
    if (dp[n] != -1)
        return dp[n];
    ll res = INF;
    for (ll k : vec)
    {
        if (n >= k)
            res = min(res, 1 + recur(n - k, vec, dp));
    }
    dp[n] = res;
    return res;
}

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
    vector<ll> dp(x + 1, -1);
    ll ans = recur(x, vec, dp);
    if (ans >= INF)
        cout << -1;
    else
        cout << ans;
}
