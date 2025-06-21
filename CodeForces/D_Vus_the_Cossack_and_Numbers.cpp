#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    double k;
    vector<ll> vec(n, 0);
    vector<bool> v(n, true);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> k;
        if (k < 0)
            vec[i] = floor(k);
        else
            vec[i] = ceil(k);
        if (vec[i] == k)
            v[i] = false;
        sum += vec[i];
    }
    if (sum > 0)
    {
        ll s = sum;
        for (ll i = 0; i < n; i++)
        {
            if (vec[i] > 0 && v[i])
            {
                vec[i]--;
                sum--;
                if (sum == 0)
                    break;
            }
        }
    }
    else if (sum < 0)
    {
        ll s = sum;
        for (ll i = 0; i < n; i++)
        {
            if (vec[i] < 0 && v[i])
            {
                vec[i]++;
                sum++;
                if (sum == 0)
                    break;
            }
        }
    }
    for (ll i = 0; i < n; i++)
    {
        cout << vec[i] << endl;
    }
}