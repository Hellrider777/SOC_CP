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

    ll n, k;
    cin >> n >> k;
    vector<ll> vec(n);
    for (ll i = 0; i < n; i++)
        cin >> vec[i];

    // Difference array to efficiently count frequencies
    vector<ll> ind(n + 1, 0); // n+1 to avoid out-of-bound

    ll a, b;
    for (ll j = 0; j < k; j++)
    {
        cin >> a >> b;
        ind[a - 1]++;
        ind[b]--;
    }

    // Convert difference array to prefix sum
    for (ll i = 1; i < n; i++)
    {
        ind[i] += ind[i - 1];
    }

    ind.pop_back(); // remove extra element

    sort(vec.begin(), vec.end());
    sort(ind.begin(), ind.end());

    ll prod = 0;
    for (ll i = 0; i < n; i++)
    {
        prod += ind[i] * vec[i];
    }

    cout << prod << '\n';
}
