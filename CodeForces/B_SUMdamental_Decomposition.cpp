#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

int calc2(int b)
{
    int l = 1;
    int cnt = 0;
    for (int i = 0; i < 28; i++)
    {
        l = pow(2, i);
        if (l > b)
            break;
        if (b & l == l)
            cnt++;
    }
    return cnt;
}
int calc(int a, int b)
{
    int k = 0;
    if (b == 1)
        k = 1;
    if (b > 1)
        k = calc2(b);
    if (a <= k)
        return b;
    else
    {
        int r = a - k;
        int s = r % 2;
        int t = r / 2;
        return (b + t * 2 + s * 4);
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << calc(a, b) << endl;
    }
}