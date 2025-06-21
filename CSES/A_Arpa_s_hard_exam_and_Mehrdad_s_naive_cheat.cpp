#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    if (n == 0)
        cout << 1 << '\n'; // because 1378^0 = 1
    else
    {
        vector<int> cycle = {8, 4, 2, 6};
        cout << cycle[(n - 1) % 4] << '\n';
    }
}
