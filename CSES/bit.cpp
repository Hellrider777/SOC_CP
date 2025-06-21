#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long calc(long long n, vector<long long> vec)
{
    if (n == 1)
        return 2;
    if (n <= vec.size())
        return vec[n - 1];
    return ((2 * calc(n - 1, vec)) % (1000000007));
    vec.push_back(((2 * calc(n - 1, vec)) % (1000000007)));
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> vec = {2};
    cout << calc(n, vec);
    return 0;
}