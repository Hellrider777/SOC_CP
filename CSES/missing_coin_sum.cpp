#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool test(int n, vector<int> vec)
{
    if (vec[vec.size() - 1] == n)
        return false;
    if (vec[0] > n)
        return true;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        if ((n == vec[i]))
            return false;
        if ((vec[i] < n && vec[i + 1] > n))
        {
            int k = n;
            for (int j = i; j >= 0; j--)
            {
                if (vec[j] <= k)
                    k -= vec[j];
            }
            if (k != 0)
                return true;
        }
        else if (vec[vec.size() - 1] < n)
        {
            int k = n;
            for (int j = vec.size() - 1; j >= 0; j--)
            {
                if (vec[j] <= k)
                    k -= vec[j];
            }
            if (k != 0)
                return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        sum += vec[i];
    }
    sort(vec.begin(), vec.end());
    bool flag = false;
    for (int i = 1; i < sum; i++)
    {
        if (test(i, vec))
        {
            cout << i;
            flag = true;
            break;
        }
    }
    if (!flag)
        cout << sum + 1;
    return 0;
}