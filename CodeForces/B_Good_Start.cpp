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
    ll w, h, a, b;
    ll x1, y1, x2, y2;
    for (ll i = 0; i < n; i++)
    {
        cin >> w >> h >> a >> b;
        cin >> x1 >> y1 >> x2 >> y2;
        if (((abs(x1 - x2)) % a == 0 && x1 != x2) || ((abs(y1 - y2)) % b == 0 && y1 != y2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}