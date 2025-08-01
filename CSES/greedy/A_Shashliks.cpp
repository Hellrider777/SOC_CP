#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    while (n--)
    {
        ll k, a, b, x, y;
        cin >> k >> a >> b >> x >> y;

        ll cnt = 0;

        if (x < y)
        {
            if (k >= a)
            {
                ll t = (k - a) / x + 1;
                cnt += t;
                k -= t * x;
            }
            if (k >= b)
            {
                ll t = (k - b) / y + 1;
                cnt += t;
                k -= t * y;
            }
        }
        else
        {
            if (k >= b)
            {
                ll t = (k - b) / y + 1;
                cnt += t;
                k -= t * y;
            }
            if (k >= a)
            {
                ll t = (k - a) / x + 1;
                cnt += t;
                k -= t * x;
            }
        }

        cout << cnt << '\n';
    }
}
