#include <iostream>
#include <string>
using namespace std;

int main()
{
    string l;
    cin >> l;
    long long count = 1;
    long long max = 1;
    for (long long i = 0; i < l.length(); i++)
    {
        if (l[i] == l[i + 1])
            count++;
        else
        {
            max = max < count ? count : max;
            count = 1;
        }
    }

    cout << max << endl;
}