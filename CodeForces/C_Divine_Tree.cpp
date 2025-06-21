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
    ll l, d;
    while (n--)
    {
        cin >> l >> d;
        if (d < l - 1 || d > (l * (l - 1) / 2))
        {
            cout << -1 << endl;
            continue;
        }
        cout << 1 << endl;

        ll k1 = l - 1;
        ll k2 = 2 * l - 2;
        ll found = -1;
        ll rem;
        ll div;
        for (ll i = 1; i < l; i++)
        {
            if (d >= k1 && d < k2)
            {
                found = i;
                rem = d - k1;
                break;
            }
            k1 = k2;
            k2 = k2 + l - 1 - i;
        }
        if (found == -1)
        {
            for (ll i = 1; i < l; i++)
            {
                cout << i << " " << i + 1 << endl;
            }
            continue;
        }
        for (ll i = 1; i <= found; i++)
        {
            cout << i << " " << i + 1 << endl;
        }

        ll cnt = 0;
        for (ll i = 0; i < (l - found - 1); i++)
        {
            if (i < rem)
                cout << found + 1 << " " << found + 2 + i << endl;
            else
                cout << found << " " << found + 2 + i << endl;
        }
    }
}