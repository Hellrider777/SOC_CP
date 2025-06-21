#include <iostream>
#include <vector>
#include <set>
using namespace std;

int f(int x, int y)
{
    return x % y + y % x;
}

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

        multiset<int> s;
        vector<int> result;
        int max_beauty = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int x : s)
            {
                max_beauty = max(max_beauty, f(a[i], x));
            }

            s.insert(a[i]);

            if (s.size() > 50)
            {
                auto it = s.begin();
                s.erase(it);
            }

            result.push_back(max_beauty);
        }

        for (int x : result)
            cout << x << " ";
        cout << '\n';
    }

    return 0;
}
