#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int k;
    int cnt = 1;
    int num1, num;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        cnt = 1;
        cin >> num1;
        for (int j = 1; j < k; j++)
        {
            cin >> num;
            if ((num1 + 1) < num)
            {
                cnt++;
                num1 = num;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}