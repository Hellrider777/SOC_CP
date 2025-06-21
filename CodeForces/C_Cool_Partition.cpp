#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;

        // Track last occurrence of each element
        vector<int> last_pos(n + 1, -1);
        for (int i = 0; i < n; i++)
        {
            last_pos[a[i]] = i;
        }

        int ans = 0;
        int max_last = -1;

        for (int i = 0; i < n; i++)
        {
            max_last = max(max_last, last_pos[a[i]]);

            // If current index is the max last occurrence of all elements seen so far,
            // we can make a cut here
            if (i == max_last)
            {
                ans++;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
