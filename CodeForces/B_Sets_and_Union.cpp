#include <iostream>
#include <vector>
#include <set>
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

        vector<set<int>> sets(n);
        set<int> full_union;

        // Read sets
        for (int i = 0; i < n; ++i)
        {
            int k;
            cin >> k;
            for (int j = 0; j < k; ++j)
            {
                int x;
                cin >> x;
                sets[i].insert(x);
                full_union.insert(x);
            }
        }

        int max_size = 0;

        // For each element in the full union, try to exclude it
        for (int excluded_element : full_union)
        {
            set<int> union_without_element;

            // Take union of all sets that don't contain the excluded element
            for (int i = 0; i < n; ++i)
            {
                if (sets[i].find(excluded_element) == sets[i].end())
                {
                    union_without_element.insert(sets[i].begin(), sets[i].end());
                }
            }

            max_size = max(max_size, (int)union_without_element.size());
        }

        cout << max_size << endl;
    }

    return 0;
}
