#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long k;
    for (long long i = 0; i < n; i++)
    {
        cin >> k;
        long long take = 0;
        bool ch = true;
        while (k > 0)
        {
            long long sum = 0;
            if (k % 4 == 0 && k > 4)
            {
                sum++;
                k--;
            }
            else if (k % 2 == 1)
            {
                sum++;
                k--;
            }
            else
            {
                sum += (k / 2);
                k /= 2;
            }
            if (ch)
            {
                take += sum;
                ch = false;
            }
            else
            {
                ch = true;
            }
        }
        cout << take << endl;
    }
}