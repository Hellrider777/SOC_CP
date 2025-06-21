#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

void precompute(ll max, vector<bool> &prime)
{
    prime[1] = false;
    for (ll i = 2; i <= max; i++)
    {
        if (prime[i])
        {
            for (ll j = i * i; j <= max; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> vec(n, 0);
    ll max = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> vec[i];
        max = max > vec[i] ? max : vec[i];
    }
    vector<bool> prime(max + 1, true);
    precompute(max, prime);
    vector<ll> pr;
    for (ll i = 1; i <= max; i++)
    {
        if (prime[i])
            pr.push_back(i);
    }

    for (auto i : vec)
    {
        ll prod = 1;
        for (auto j : pr)
        {
            if (i == 1)
                break;
            ll num = 0;
            while (i % j == 0)
            {
                num++;
                i /= j;
            }
            prod *= (num + 1);
        }
        cout << prod << endl;
    }
}
