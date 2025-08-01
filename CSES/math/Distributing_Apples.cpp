#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

// Fast exponentiation
ll power(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// Precompute factorials and inverse factorials
void precompute(vector<ll> &fact, vector<ll> &invfact, ll maxn)
{
    fact[0] = 1;
    for (ll i = 1; i <= maxn; i++)
        fact[i] = fact[i - 1] * i % MOD;
    invfact[maxn] = power(fact[maxn], MOD - 2, MOD);
    for (ll i = maxn - 1; i >= 0; i--)
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
}

ll binom(ll n, ll k, const vector<ll> &fact, const vector<ll> &invfact)
{
    if (k < 0 || k > n)
        return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<ll, ll>> queries(2);
    ll maxn = 0;
    ll a, b;
    cin >> a >> b;
    maxn = a + b - 1;

    vector<ll> fact(maxn + 1), invfact(maxn + 1);
    precompute(fact, invfact, maxn);

    cout << binom(a + b - 1, b, fact, invfact);

    return 0;
}
