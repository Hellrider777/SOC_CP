#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a, b;
    string l;
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        cin >> l;
        cnt1 = 0;
        cnt0 = 0;
        for (int j = 0; j < a; j++)
        {
            if (l[j] == '1')
                cnt1++;
            else
                cnt0++;
        }
        // cout << cnt1 << cnt0 << endl;
        int min = cnt1 < cnt0 ? cnt1 : cnt0;
        int diff = cnt1 >= cnt0 ? cnt1 - cnt0 : cnt0 - cnt1;
        diff /= 2;

        if ((cnt1 / 2 + cnt0 / 2) < b)
            cout << "NO" << endl;

        else if ((diff <= b) && ((b - diff) % 2 == 0))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}