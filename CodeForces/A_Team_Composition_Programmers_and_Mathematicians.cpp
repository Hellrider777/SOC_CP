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
    while (n--)
    {
        ll a, b;
        cin >> a >> b;
        ll j = (a + b) / 4;
        if (a < j)
            cout << a << endl;
        else if (b < j)
            cout << b << endl;
        else
            cout << j << endl;
    }
}