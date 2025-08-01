#include <iostream>
using namespace std;

void recur(long long n)
{
    if (n == 1)
    {
        cout << n << " ";
    }
    else if (n % 2 == 0)
    {
        cout << n << " ";
        recur(n / 2);
    }
    else if (n % 2 == 1)
    {
        cout << n << " ";
        recur(3 * n + 1);
    }
}

int main()
{
    long long n;
    cin >> n;
    recur(n);
}