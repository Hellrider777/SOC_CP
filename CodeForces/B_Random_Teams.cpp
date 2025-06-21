#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;

using namespace std;

int main()
{
    ll n, m;
    cin >> n >> m;
    ll max = ((n - m) * (n - m + 1)) / 2;
    ll rem = n % m;
    ll q = n / m;
    ll k1 = (q * (q - 1)) / 2;
    ll k2 = (q * (q + 1)) / 2;
    ll min = rem * k2 + (m - rem) * k1;
    cout << min << " " << max;
}