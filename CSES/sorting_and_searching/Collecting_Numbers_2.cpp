#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt(const vector<int> &pos)
{

    int rounds = 1;
    int n = pos.size() - 1; // Because pos[0] is unused

    for (int i = 2; i <= n; i++)
    {
        if (pos[i] < pos[i - 1])
        {
            rounds++;
        }
    }

    return rounds;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> vec(n);

    vector<int> pos(vec.size() + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        pos[vec[i]] = i;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> n >> m;
        swap(pos[find(pos.begin(), pos.end(), n - 1)], pos[find(pos.begin(), pos.end(), m - 1)]);
        cout << cnt(vec) << endl;
    }
    return 0;
}
