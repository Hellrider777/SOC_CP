#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> vec(n);
    map<int, vector<int>> pos;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        pos[vec[i]].push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        // Try to find any index in [l-1, r-1] where value != x
        int ans = -1;
        // Try left to right binary search
        int left = l - 1, right = r - 1;
        // All positions of x in [left, right]
        auto &vec_x = pos[x];
        int cnt_x = upper_bound(vec_x.begin(), vec_x.end(), right) - lower_bound(vec_x.begin(), vec_x.end(), left);
        if (cnt_x < (right - left + 1))
        {
            // There is at least one index in [left, right] where value != x
            for (int idx = left; idx <= right; ++idx)
            {
                if (vec[idx] != x)
                {
                    ans = idx + 1;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
