#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n, 0);
        vector<int> b(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++)
        {
            if (m == 0)
                break;
            if (a[i] < b[n - 1 - i])
            {
                a[i] = b[n - 1 - i];
                m--;
            }
            else
                break;
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += a[i];
        cout << sum << endl;
    }
}