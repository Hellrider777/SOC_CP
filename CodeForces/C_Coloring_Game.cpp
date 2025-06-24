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

        long long ans = 0;

        for (int i = 0; i < n - 2; ++i)
        {
            for (int j = i + 1; j < n - 1; ++j)
            {
                int sum_ij = a[i] + a[j];

                for (int k = j + 1; k < n; ++k)
                {
                    // Early termination - since sorted, if this k fails, all larger k will fail
                    if (a[k] >= sum_ij)
                        break;

                    int red_sum = sum_ij + a[k];

                    // Fast max non-red calculation using sorted property
                    int max_non_red = (k == n - 1) ? ((j == n - 2) ? ((i == n - 3) ? a[n - 4] : a[n - 3]) : a[n - 2]) : a[n - 1];

                    if (red_sum > max_non_red)
                    {
                        ans++;
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}