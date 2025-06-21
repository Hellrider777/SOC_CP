#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> vec;
    string ans;
    string l;
    for (int i = 0; i < n; i++)
    {
        cin >> l;
        vec.push_back(l);
    }
    ans = vec[0];
    for (int j = 0; j < n; j++)
    {
        string k = vec[j];
        for (int i = 0; i < k.length(); i++)
        {
            if (k[i] != '.')
            {
                ans[i] = k[i];
            }
            else if (ans[i] == '.')
            {
                ans[i] = '.';
            }
        }
    }

    cout << ans;
    return 0;
}