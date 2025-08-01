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

    ll t;
    cin >> t;
    vector<pair<ll, ll>> queries(t);
    ll maxn = 0;
    for (ll i = 0; i < t; i++)
    {
        cin >> queries[i].first >> queries[i].second;
        maxn = max(maxn, queries[i].first);
    }

    vector<ll> fact(maxn + 1), invfact(maxn + 1);
    precompute(fact, invfact, maxn);

    for (auto f : queries)
    {
        cout << binom(f.first, f.second, fact, invfact) << '\n';
    }
    return 0;
}
