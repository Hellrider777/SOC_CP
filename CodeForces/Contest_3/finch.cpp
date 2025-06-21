#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> finches(n);
    for (int i = 0; i < n; i++)
    {
        cin >> finches[i].first >> finches[i].second;
    }

    map<int, long long> jetAdd;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        jetAdd[x] += y;
    }

    // Prepare prefix sums over sorted keys
    vector<pair<int, long long>> sortedJets(jetAdd.begin(), jetAdd.end());
    vector<long long> prefix(sortedJets.size(), 0);
    prefix[0] = sortedJets[0].second;
    for (size_t i = 1; i < sortedJets.size(); i++)
    {
        prefix[i] = prefix[i - 1] + sortedJets[i].second;
    }

    // For each finch, compute the result
    for (int i = 0; i < n; i++)
    {
        int a = finches[i].first;
        int b = finches[i].second;

        long long result = a;
        // Add y where x == b
        if (jetAdd.count(b))
        {
            result += jetAdd[b];
        }

        // Add 2*y where x < b
        auto it = lower_bound(sortedJets.begin(), sortedJets.end(), make_pair(b, 0LL));
        if (it != sortedJets.begin())
        {
            int idx = distance(sortedJets.begin(), it) - 1;
            result += 2 * prefix[idx];
        }

        cout << result << " ";
    }

    return 0;
}
