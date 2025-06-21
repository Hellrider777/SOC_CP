#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int i = 0;
    int j = n - 1;
    int cnt = 0;
    while (i <= j)
    {
        if (i == j)
        {
            cnt++;
            break;
        }
        if (vec[j] + vec[i] <= m)
        {
            cnt++;
            i++;
            j--;
        }
        else
        {
            j--;
            cnt++;
        }
    }
    cout << cnt;
}