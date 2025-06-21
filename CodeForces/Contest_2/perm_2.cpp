#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    if (n == 1)
    {
        cout << -1 << endl;
        return 0;
    }

    vector<long long> perm(n), result(n);

    for (long long i = 0; i < n; i++)
    {
        perm[i] = (i + 1) % n; // circular shift by 1
        result[i] = (perm[i] + i) % n;
    }

    set<int> s1(perm.begin(), perm.end());
    set<int> s2(result.begin(), result.end());
    if (s1.size() == n && s2.size() == n)
    {
        for (long long i = 0; i < n; i++)
            cout << i << " ";
        cout << endl;

        for (long long x : perm)
            cout << x << " ";
        cout << endl;

        for (long long x : result)
            cout << x << " ";
        cout << endl;
    }
    else
    {
        cout << -1;
    }

    return 0;
}
