#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a, b, c;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        if ((a - b) > 1 || (a + b) > n - 2)
            cout << -1;
        else
        {
            for (int i = 0; i < b; i++)
            {
            }
        }
    }
}