#include <iostream>
#include <vector>
#include <algorithm>
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
    ll a, b, c, d;
    for (ll i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d;
        if (min(b, d) <= min(a, c))
            cout << "Gellyfish" << endl;
        else
            cout << "Flower" << endl;
    }
}