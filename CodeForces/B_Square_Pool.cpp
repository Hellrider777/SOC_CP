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
    ll n, s;
    ll dx, dy, x, y;
    while (t--)
    {
        cin >> n >> s;
        ll cnt = 0;
        while (n--)
        {
            cin >> dx >> dy >> x >> y;
            if (x == y && (dx == dy))
                cnt++;
            if (x + y == s && (dx == -dy))
                cnt++;
        }
        cout << cnt << endl;
    }
}