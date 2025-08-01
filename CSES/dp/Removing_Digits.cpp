#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;
const ll inf = 1e9;

ll recur(ll n, vector<ll> &dp)
{
    if (n < 0)
        return inf;
    if (n == 0)
        return 0;
    if (dp[n] != inf)
        return dp[n];
    ll cnt = inf;
    ll k = n;
    while (k > 0)
    {
        if (k % 10 != 0)
            cnt = cnt < recur(n - (k % 10), dp) + 1 ? cnt : recur(n - (k % 10), dp) + 1;
        k /= 10;
    }
    dp[n] = cnt;
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> dp(n + 1, inf);
    cout << recur(n, dp);
}