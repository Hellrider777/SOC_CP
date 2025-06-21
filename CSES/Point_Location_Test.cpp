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
    ll x1, y1, x2, y2, x3, y3;
    while (n--)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        ll prod = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
        if (prod < 0)
            cout << "RIGHT" << endl;
        else if (prod == 0)
            cout << "TOUCH" << endl;
        else
            cout << "LEFT" << endl;
    }
}