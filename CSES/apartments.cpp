#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> app(n);
    vector<int> desired(m);

    for (int i = 0; i < n; i++)
        cin >> app[i];
    for (int i = 0; i < m; i++)
        cin >> desired[i];

    sort(app.begin(), app.end());
    sort(desired.begin(), desired.end());

    int i = 0, j = 0, count = 0;

    while (i < n && j < m)
    {
        if (abs(app[i] - desired[j]) <= k)
        {
            count++;
            i++;
            j++;
        }
        else if (app[i] < desired[j] - k)
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    cout << count << endl;
    return 0;
}
