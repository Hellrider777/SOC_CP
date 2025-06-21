#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long spiral(long long m, long long n)
{
    if (m > n)
    {
        long long k = (m * m) - m + 1;
        if (m % 2 == 0)
        {
            return (k + m - n);
        }
        if (m % 2 != 0)
        {
            return (k - m + n);
        }
    }
    if (m < n)
    {
        long long k = (n * n) - n + 1;
        if (n % 2 == 0)
        {
            return (k + m - n);
        }
        if (n % 2 != 0)
        {
            return (k - m + n);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    long long k1, k2;
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> k1 >> k2;

        arr[i] = spiral(k1, k2);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}