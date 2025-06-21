#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> vec;
    for (long long i = 0; i < n; i++)
    {
        long long l;
        cin >> l;
        vec.push_back(l);
    }

    long long num = vec[0];
    long long count = 0;

    for (long long i = 0; i < n; i++)
    {
        if (vec[i] < num)
        {
            count += (num - vec[i]);
        }
        else if (vec[i] > num)
            num = vec[i];
    }

    cout << count;
}