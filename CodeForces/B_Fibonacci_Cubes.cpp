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
    vector<ll> fib = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    ll n;
    cin >> n;
    ll a, b;
    vector<ll> tri(3, 0);
    for (ll i = 0; i < n; i++)
    {
        string l = "";
        cin >> a >> b;
        for (ll j = 0; j < b; j++)
        {
            cin >> tri[0] >> tri[1] >> tri[2];
            sort(tri.begin(), tri.end());
            ll len = fib[a] + fib[a - 1];
            ll sh = fib[a];
            if ((tri[2] >= len) && (tri[1] >= sh) && (tri[0] >= sh))
            {
                l.push_back('1');
            }
            else
                l.push_back('0');
        }
        cout << l << endl;
    }
}