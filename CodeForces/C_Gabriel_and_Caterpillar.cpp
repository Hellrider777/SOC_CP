#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int h1, h2;
    cin >> h1 >> h2;
    int a, b;
    cin >> a >> b;
    int ans = 0;
    int rem = h2 - h1;
    if (a <= b)
    {
        if ((h2 - h1) <= 8 * a)
            cout << 0;
        else
            cout << -1;
    }
    else
    {
        while (true)
        {
            if (rem <= (8 * a))
            {
                cout << ans;
                break;
            }
            rem -= (12 * (a - b));
            ans++;
        }
    }
}