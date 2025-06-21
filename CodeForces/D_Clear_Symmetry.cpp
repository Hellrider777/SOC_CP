#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a2 = 1;
    for (int i = 1; i <= 15; i++)
    {
        if (i % 2 == 1)
            a2 = (i * i + 1) / 2;
        else
            a2 = (i * i) / 2;
        if (n == 1)
        {
            cout << 1;
            break;
        }
        else if (n <= a2)
        {
            cout << i;
            break;
        }
    }
}