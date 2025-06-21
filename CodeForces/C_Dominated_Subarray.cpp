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
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        int l;
        int ctr = k;
        bool flag = false;
        vector<int> vec(200001, -1);
        for (int j = 0; j < k; j++)
        {
            cin >> l;
            if (vec[l] != -1)
            {
                ctr = (j - vec[l] + 1) < ctr ? (j - vec[l] + 1) : ctr;
                flag = true;
            }
            vec[l] = j;
        }
        if (k < 2)
        {
            cout << -1 << endl;
            continue;
        }
        else if (!flag)
            cout << -1 << endl;
        else
            cout << ctr << endl;
    }
}