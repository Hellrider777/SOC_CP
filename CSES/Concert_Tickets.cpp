#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    multiset<int> tickets;
    vector<pair<int, int>> cust(m); // {max_price, original_index}

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        tickets.insert(t);
    }

    for (int i = 0; i < m; i++)
    {
        int c;
        cin >> c;
        cust[i] = make_pair(c, i);
    }

    vector<int> ans(m);
    for (size_t i = 0; i < cust.size(); ++i)
    {
        int max_price = cust[i].first;
        int idx = cust[i].second;

        auto it = tickets.upper_bound(max_price);
        if (it == tickets.begin())
        {
            ans[idx] = -1;
        }
        else
        {
            --it;
            ans[idx] = *it;
            tickets.erase(it);
        }
    }

    for (int val : ans)
        cout << val << endl;
}
