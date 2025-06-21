#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int hcf(int a, int b)
{
    int m1 = a > b ? a : b;
    int m2 = a < b ? a : b;
    int max = 1;
    for (int i = 1; i <= m2; i++)
    {
        if ((m1 % i == 0) && (m2 % i == 0))
            max = i;
    }
    return max;
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int s1, s2;
    if (a * d > b * c)
    {
        s1 = ((a * d) - (b * c));
        s2 = (a * d);
    }
    else if (a * d == b * c)
    {
        cout << 0 << "/" << 1;
        return 0;
    }
    else
    {
        s1 = ((b * c) - (a * d));
        s2 = (b * c);
    }
    int p1 = s1 / (hcf(s1, s2));
    int p2 = s2 / (hcf(s1, s2));
    cout << p1 << "/" << p2;
}