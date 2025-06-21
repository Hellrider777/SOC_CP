#include <iostream>
#include <vector>
#include <string>
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

ll binom(ll n, const vector<ll> &fact, const vector<ll> &invfact)
{
    if (n < 1)
        return 1;
    return fact[(2 * n) - 2] * invfact[n] % MOD * invfact[n - 1] % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a;
    string l;
    cin >> a;
    cin >> l;
    ll sum = 0;
    for (ll i = 0; i < l.size(); i++)
    {
        if (sum < 0)
        {
            cout << 0;
            return 0;
        }
        if (l[i] == '(')
            sum++;
        else
            sum--;
    }
    ll inp = a - l.size() - sum;
    if (sum < 0 || inp < 0 || inp % 2 != 0)
    {
        cout << 0;
        return 0;
    }
    else if (inp == 0)
    {
        cout << 1;
        return 0;
    }
    ll maxn = (2 * inp) - 2;

    vector<ll> fact(maxn + 1), invfact(maxn + 1);
    precompute(fact, invfact, maxn);

    cout << ((sum + 1) * binom(inp, fact, invfact)) % MOD;

    return 0;
}