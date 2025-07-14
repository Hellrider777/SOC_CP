#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        string a, b;
        cin >> a >> b;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        string result = "";
        int i = 0, j = 0;
        int streak_a = 0, streak_b = 0;

        while (i < n && j < m)
        {
            if ((a[i] <= b[j] && streak_a < k) || streak_b == k)
            {
                result += a[i++];
                streak_a++;
                streak_b = 0;
            }
            else
            {
                result += b[j++];
                streak_b++;
                streak_a = 0;
            }
        }

        cout << result << endl;
    }
}
