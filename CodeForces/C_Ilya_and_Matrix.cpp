#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> vec(n);
    ll totalSum = 0;

    for (ll i = 0; i < n; ++i)
    {
        cin >> vec[i];
        totalSum += vec[i];
    }

    sort(vec.begin(), vec.end(), greater<ll>());

    for (ll size = n / 4; size > 0; size /= 4)
    {
        for (ll i = 0; i < size; ++i)
        {
            totalSum += vec[i];
        }
    }

    cout << totalSum << endl;
    return 0;
}
