#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> D(n + 2, 0);
    D[0] = 1;
    if (n > 0)
        D[1] = 0;
    for (ll i = 2; i <= n; i++)
    {
        D[i] = ((i - 1) * (D[i - 1] + D[i - 2])) % MOD;
    }
    cout << D[n] << '\n';
    return 0;
}
