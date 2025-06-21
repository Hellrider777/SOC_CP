#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int a, b;
    int k = 0;
    vector<int> vec(n, 0);
    int ctr = 2;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        int t1 = (pow(2, b) - pow(2, a - 1));
        if ((t1 & k) == 0)
        {
            vec[i] = 1;
            k += t1;
        }
        else
        {
            vec[i] = ctr;
            ctr++;
            k |= t1;
        }
    }
    cout << ctr - 1 << endl;
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
}