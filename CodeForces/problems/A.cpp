#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int calc(vector<int> vec, int min, int max, int cnt = 0)
{

    sort(vec.begin(), vec.end());
    while (min <= max)
    {
        if ((vec[min] + vec[max]) % 2 == 0)
        {
            break;
        }
        else
        {
            int ans = calc(vec, min + 1, max) < calc(vec, min, max - 1) ? calc(vec, min + 1, max, cnt + 1) : calc(vec, min, max - 1, cnt + 1);
            return ans;
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    int m;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        vector<int> vec(m, 0);
        for (int j = 0; j < m; j++)
        {
            cin >> vec[j];
        }
        int min = 0, max = m;
        cout << calc(vec, min, max - 1) << endl;
    }
    return 0;
}