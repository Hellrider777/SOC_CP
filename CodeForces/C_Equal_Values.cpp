#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // Map from element to vector of consecutive segments: pairs (start, end)
        unordered_map<int, vector<pair<int, int>>> segments;

        // Find consecutive segments for each element
        for (int i = 0; i < n;)
        {
            int val = a[i];
            int j = i;
            while (j < n && a[j] == val)
                j++;
            // segment [i, j-1]
            segments[val].push_back({i, j - 1});
            i = j;
        }

        ll ans = n * n;

        // Calculate cost for each element
        for (auto &p : segments)
        {
            int val = p.first;
            auto &segs = p.second;

            // Cost if we do left operation at first segment start (make left part equal val)
            // and right operation at last segment end (make right part equal val)
            // Also cost of filling gaps between segments by repeated right/left operations
            ll cost = 0;

            // Left operation cost: positions before first segment start
            cost += (ll)(segs[0].first) * val;

            // Right operation cost: positions after last segment end
            cost += (ll)(n - 1 - segs.back().second) * val;

            // For gaps between consecutive segments, fill with the element:
            // cost = gap_length * val
            for (size_t i = 1; i < segs.size(); i++)
            {
                int gap = segs[i].first - segs[i - 1].second - 1;
                cost += (ll)gap * val;
            }

            ans = min(ans, cost);
        }

        cout << ans << "\n";
    }
    return 0;
}
