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
    int n;
    cin >> n;
    int k;
    for (int i = 0; i < n; i++)
    {
        int k1 = 2;
        int k2 = 1;
        vector<int> vec = {0, 0, 0};
        int k;
        cin >> k;
        int ctr = 0;
        while (true)
        {
            int kr = (2 * vec[k2]) + 1;
            if (kr >= k)
            {
                ctr += 3;
                break;
            }
            vec[k1] = kr;
            int tmp = 3 - k1 - k2;
            k1 = k2;
            k2 = tmp;
            ctr++;
        }
        cout << ctr << endl;
    }
}