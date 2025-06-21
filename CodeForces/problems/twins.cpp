#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        sum += vec[i];
    }
    sum = sum / 2;
    vector<int> ans;
    sort(vec.begin(), vec.end());
    for (int i = n - 1; i >= 0; i--)
    {
        if (sum <= 0)
            break;
        sum -= vec[i];
        ans.push_back(vec[i]);
    }
    int min = ans.size() < (n - ans.size()) ? ans.size() : (n - ans.size());
    if (sum == 0)
        cout << min + 1;
    else
        cout << ans.size();
}