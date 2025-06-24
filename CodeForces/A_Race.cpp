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
    ll a, x, y;
    while (n--)
    {
        cin >> a >> x >> y;
        ll k2 = x > y ? x : y;
        ll k1 = x < y ? x : y;
        if (a < k1)
        {
            cout << "YES";
        }
        else if (a > k2)
        {
            cout << "YES";
        }
        else if (a >= k1 && a <= k2)
            cout << "NO";
        cout << endl;
    }
}