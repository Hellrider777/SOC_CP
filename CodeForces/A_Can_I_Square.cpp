#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

bool isPerfectSquare(ll n)
{
    if (n < 0)
        return false; // negative numbers can't be perfect squares

    ll root = static_cast<ll>(sqrt(n));
    return root * root == n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    ll k;
    while (n--)
    {
        cin >> k;
        ll sum = 0;
        ll t;
        while (k--)
        {
            cin >> t;
            sum += t;
        }
        if (isPerfectSquare(sum))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}