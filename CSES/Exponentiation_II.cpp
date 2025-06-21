#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

// Fast modular exponentiation: (base^exp) % mod
ll mod_pow(ll base, ll exp, ll mod)
{
    ll result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    while (n--)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        // By Fermat's Little Theorem:
        // a^(b^c) % MOD = a^(b^c % (MOD - 1)) % MOD
        ll exponent = mod_pow(b, c, MOD - 1);  // reduce b^c mod (MOD - 1)
        ll result = mod_pow(a, exponent, MOD); // now compute a^exponent mod MOD

        cout << result << '\n';
    }
}
