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
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}