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
    for (ll i = 0; i < t; i++)
    {
        ll n;
        cin >> n;
        cout << 1 << " ";
        for (ll j = n; j > 1; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}