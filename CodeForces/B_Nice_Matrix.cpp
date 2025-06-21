#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long med(long long a, long long b, long long c, long long d)
{
    vector<long long> vec = {a, b, c, d};
    sort(vec.begin(), vec.end());
    return (vec[3] + vec[2] - vec[1] - vec[0]);
}

int main()
{
    long long t;
    cin >> t;
    for (long long l = 0; l < t; l++)
    {
        long long n, m;
        cin >> n >> m;
        vector<vector<long long>> vec;
        vector<long long> row(m, 0);
        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < m; j++)
            {
                cin >> row[j];
            }
            vec.push_back(row);
        }
        long long ans = 0;
        for (long long i = 0; i < (n + 1) / 2; i++)
        {
            for (long long j = 0; j < (m + 1) / 2; j++)
            {
                long long sum = med(vec[i][j], vec[n - 1 - i][j], vec[i][m - 1 - j], vec[n - 1 - i][m - 1 - j]);
                if (i == (n - 1 - i) || j == (m - 1 - j))
                    sum /= 2;

                ans += sum;
            }
        }
        cout << ans << endl;
    }
}