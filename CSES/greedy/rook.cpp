#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long calc(long long n)
{
    long long k = n * n;
    long long fac = (k * (k - 1)) / 2;
    return (fac - ((n - 1) * (n - 2) * 4));
}

int main()
{
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cout << calc(i) << endl;
    }
    return 0;
}