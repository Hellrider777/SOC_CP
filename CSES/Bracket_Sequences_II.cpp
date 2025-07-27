#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 2e6 + 5;

vector<ll> fact(MAXN), inv_fact(MAXN);

ll mod_pow(ll a, ll b, ll m = MOD)
{
    ll res = 1;
    a %= m;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void precompute_factorials(int n)
{
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    inv_fact[n] = mod_pow(fact[n], MOD - 2);
    for (int i = n - 1; i >= 1; --i)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

ll nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string l;
    cin >> n >> l;

    if (n % 2 != 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    int open = 0, close = 0;
    for (char c : l)
    {
        if (c == '(')
            open++;
        else
            close++;
        if (close > open)
        {
            cout << 0 << "\n"; // invalid prefix
            return 0;
        }
    }

    int rem = n - l.size();
    int balance = open - close;

    if ((rem - balance) % 2 != 0 || rem < balance)
    {
        cout << 0 << "\n";
        return 0;
    }

    int a = (rem - balance) / 2; // '(' to add
    int b = rem - a;             // ')' to add

    precompute_factorials(a + b + 2);

    // Ballot-based formula: (balance + 1) / (a + 1) * C(a + b, a)
    ll ans = (balance + 1) * nCr(a + b, a) % MOD * mod_pow(a + 1, MOD - 2) % MOD;
    cout << ans << "\n";
    return 0;
}
