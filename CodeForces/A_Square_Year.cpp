#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int calc(int n)
{

    for (int i = 0; i < 100; i++)
    {
        if (i * i == n)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int num;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        ans = calc(num);
        if (ans == -1)
            cout << -1 << endl;
        else
            cout << 0 << " " << ans << endl;
    }
    return 0;
}