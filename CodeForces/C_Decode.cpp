#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();

        ll ans = 0;

        // Map to count prefix sums and their contribution
        map<int, ll> prefixCount;
        map<int, ll> prefixSum;

        int currentPrefix = 0;
        prefixCount[0] = 1; // Empty prefix
        prefixSum[0] = 1;   // Contribution of empty prefix (position 1)

        // For each position j (0-indexed)
        for (int j = 0; j < n; j++)
        {
            // Update current prefix sum
            currentPrefix += (s[j] == '1' ? 1 : -1);

            // Count balanced substrings ending at position j
            if (prefixCount.count(currentPrefix))
            {
                // Add contribution of all substrings ending at j
                ll contribution = prefixSum[currentPrefix] * (n - j);
                ans = (ans + contribution) % MOD;
            }

            // Update maps for next iteration
            prefixCount[currentPrefix]++;
            prefixSum[currentPrefix] = (prefixSum[currentPrefix] + (j + 2)) % MOD;
        }

        cout << ans << endl;
    }
    return 0;
}
