#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> vec(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    ll med;
    if (vec.size() % 2 == 1)
    {
        med = vec[vec.size() / 2];
    }
    else
        med = (vec[vec.size() / 2] + vec[(vec.size() / 2) - 1]) / 2;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        ll s = med > vec[i] ? (med - vec[i]) : (vec[i] - med);
        sum += s;
    }
    cout << sum;
}