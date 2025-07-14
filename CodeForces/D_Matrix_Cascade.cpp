#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void invert(vector<vector<int>> &a, int i, int j, int n)
{
    a[i][j] ^= 1;
    for (int x = i + 1; x < n; ++x)
    {
        for (int y = 0; y < n; ++y)
        {
            if (x - i >= abs(y - j))
            {
                a[x][y] ^= 1;
            }
        }
    }
}

bool allZero(const vector<vector<int>> &a)
{
    for (const auto &row : a)
        for (int val : row)
            if (val)
                return false;
    return true;
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
        vector<vector<int>> a(n, vector<int>(n));
        string s;

        for (int i = 0; i < n; ++i)
        {
            cin >> s;
            for (int j = 0; j < n; ++j)
            {
                a[i][j] = s[j] - '0';
            }
        }

        int steps = 0;

        // Loop until all elements are 0
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (a[i][j] == 1)
                {
                    invert(a, i, j, n);
                    ++steps;
                }
            }
        }

        cout << steps << '\n';
    }

    return 0;
}
