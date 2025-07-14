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
        ll k, q;
        cin >> k >> q;
        vector<ll> vec1(k, 0);
        cin >> vec1[0];
        ll min = vec1[0];
        for (ll i = 1; i < k; i++)
        {
            cin >> vec1[i];
            min = min < vec1[i] ? min : vec1[i];
        }
        for (ll i = 0; i < q; i++)
        {
            ll l;
            cin >> l;
            l = l < min - 1 ? l : min - 1;
            cout << l << " ";
        }
        cout << endl;
    }
}