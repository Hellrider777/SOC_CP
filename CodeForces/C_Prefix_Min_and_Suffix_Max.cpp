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
    ll n;
    while (t--)
    {
        string l = "1";
        cin >> n;
        vector<ll> vec(n, 0);
        for (ll i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        vector<ll> mx(n, 0);
        vector<ll> mn(n, 0);
        mn[0] = vec[0];
        mx[n - 1] = vec[n - 1];
        for (ll i = 1; i < n; i++)
        {
            mn[i] = mn[i - 1] < vec[i] ? mn[i - 1] : vec[i];
            mx[n - i - 1] = mx[n - i] > vec[n - i - 1] ? mx[n - i] : vec[n - i - 1];
        }
        for (ll i = 1; i < n - 1; i++)
        {
            if (((mn[i - 1] <= vec[i]) && (mx[i + 1] <= vec[i])) || ((mn[i - 1] >= vec[i]) && (mx[i + 1] >= vec[i])) || ((mn[i - 1] >= vec[i]) && (mx[i + 1] <= vec[i])))
            {
                l += '1';
            }
            else
                l += '0';
        }
        l += '1';
        cout << l << endl;
    }
}