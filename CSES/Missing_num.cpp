#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    int l;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> l;
        vec.push_back(l);
    }
    sort(vec.begin(), vec.end());
    vec.push_back(0);

    for (int i = 1; i <= n; i++)
    {
        if (vec[i - 1] != i)
        {
            cout << i << endl;
            break;
        }
    }
}
