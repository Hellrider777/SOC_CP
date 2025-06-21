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
    vector<ll> vec;
    ll k;
    cin >> k;
    ll curr_max = k;
    ll max_so_far = k;
    n--;
    while (n--)
    {
        cin >> k;
        curr_max = max(k, curr_max + k);
        max_so_far = max(max_so_far, curr_max);
    }
    cout << max_so_far;
}