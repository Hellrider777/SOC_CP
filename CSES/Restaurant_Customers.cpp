#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    map<int, int> mp; // Use map instead of unordered_map to iterate in sorted order
    int a, b;

    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        mp[a]++;
        mp[b + 1]--; // Use b+1 to correctly represent the end of the interval
    }

    int ans = 0;
    int current = 0;

    for (auto const item : mp)
    {
        current += item.second;
        ans = max(ans, current);
    }

    cout << ans << endl;

    return 0;
}
