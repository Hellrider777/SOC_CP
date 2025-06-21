#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n, x;
        cin >> n >> x;
        int i1 = 0;
        int i2 = 0;
        bool flag = true;
        int k;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            if (k == 1 && flag)
            {
                i1 = i;
                flag = false;
            }
            else if (k == 1)
            {
                i2 = i;
            }
        }
        int ans = i2 - i1 + 1;
        if (ans <= x)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}