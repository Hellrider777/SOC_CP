#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n;
    long long m;
    cin >> n >> m;
    long long min = 0;
    long long k;
    long long cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if (i == n - 1)
        {
            if ((min + k) % m == 0)
                cnt += (min + k) / m;
            else
                cnt += ((min + k) / m + 1);
        }
        else if (min == 0 && k < m)
        {
            min = k;
        }
        else if ((min + k) <= m)
        {
            cnt++;
            min = 0;
        }
        else
        {
            cnt += (min + k) / m;
            min = (min + k) % m;
        }
    }
    cout << cnt;
    return 0;
}
