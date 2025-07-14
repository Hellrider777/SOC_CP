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
    ll t;
    cin >> t;
    ll n, j, k;
    while (t--)
    {
        cin >> n >> j >> k;
        vector<ll> vec(n, 0);
        ll max = 0;
        ll th = 2;
        for (ll i = 0; i < n; i++)
        {
            cin >> vec[i];
            max = max > vec[i] ? max : vec[i];
        }
        if (vec[j - 1] == max)
            th = 1;
        if (k >= th)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}