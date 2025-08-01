#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> pos1(n + 1, -1);
    vector<long long> pos2(n + 1, -1);

    long long l;
    for (long long i = 0; i < 2 * n; i++)
    {
        cin >> l;
        if (pos1[l] == -1)
            pos1[l] = i;
        else
            pos2[l] = i;
    }
    long long ind1 = 0, ind2 = 0;
    long long ans = 0;
    long long s;
    for (long long i = 1; i < n + 1; i++)
    {
        if ((abs(ind1 - pos1[i]) + abs(ind2 - pos2[i])) < (abs(ind2 - pos1[i]) + abs(ind1 - pos2[i])))
        {
            ans += (abs(ind1 - pos1[i]) + abs(ind2 - pos2[i]));
            ind1 = pos1[i];
            ind2 = pos2[i];
        }
        else
        {
            ans += (abs(ind2 - pos1[i]) + abs(ind1 - pos2[i]));
            ind2 = pos1[i];
            ind1 = pos2[i];
        }
    }
    cout << ans;
}
