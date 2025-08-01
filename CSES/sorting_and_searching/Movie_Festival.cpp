#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int a, b;
    multimap<int, int> mp;
    while (n--)
    {
        cin >> b >> a;
        mp.insert({a, b});
    }
    int ans = 0;
    int st = 1;
    for (auto item : mp)
    {
        if (item.second >= st)
        {
            ans++;
            st = item.first;
        }
    }
    cout << ans;
}