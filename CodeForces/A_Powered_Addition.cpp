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
    for (ll i = 0; i < n; i++)
    {
        ll m;
        cin >> m;
        ll curr;
        cin >> curr;
        ll diff = 0;
        ll next;
        for (ll j = 0; j < m - 1; j++)
        {
            cin >> next;
            if (next >= curr)
                curr = next;
            else
                diff = diff > (curr - next) ? diff : (curr - next);
        }
        ll x = 1;
        ll ans = 0;
        while (diff > 0)
        {
            diff -= x;
            x *= 2;
            ans++;
        }

        cout << ans << endl;
    }
}