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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a, b, c, d;
        ll ans = 0;
        while (n--)
        {
            cin >> a >> b >> c >> d;
            if (c < a)
                ans += a - c;
            if (d < b)
            {
                ans += (b - d) + min(a, c);
            }
        }
        cout << ans << endl;
    }
}