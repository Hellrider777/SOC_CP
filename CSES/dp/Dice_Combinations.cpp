#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> vec(n + 1, 0);
    vec[0] = 1;
    vec[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        for (ll j = 1; j <= 6; j++)
        {
            if (i - j < 0)
                break;
            vec[i] += vec[i - j];
            vec[i] %= MOD;
        }
    }
    cout << vec[n];
}