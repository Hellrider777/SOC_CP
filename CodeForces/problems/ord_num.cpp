#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int calc(int n)
{
    int cnt = 0;
    int l = n;
    while (l > 0)
    {
        l = l / 10;
        cnt++;
    }
    if (cnt == 1)
        return n;
    int k = n / (pow(10, cnt - 1));
    int num = 0;
    for (int i = 0; i < cnt; i++)
    {
        num += pow(10, i) * k;
    }
    // return k;
    if (n >= num)
        return (9 * (cnt - 1) + k);
    else
        return (9 * (cnt - 1) + k - 1);
}

int main()
{
    int n;
    cin >> n;
    int k;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        vec[i] = calc(k);
    }
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << endl;
    }
    return 0;
}