#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void gray(vector<string> &vec, long long n, long long num)
{
    if (n == num)
    {
        for (long long i = 0; i < pow(2, n); i++)
        {
            cout << vec[i] << endl;
        }
    }
    else
    {

        for (long long i = 0; i < pow(2, n); i++)
        {
            vec.push_back(vec[pow(2, n) - i - 1] + '1');
            vec[pow(2, n) - i - 1] += '0';
        }
        n++;
        gray(vec, n, num);
    }
}
int main()
{
    long long n;
    cin >> n;
    vector<string> vec = {"1", "0"};
    gray(vec, 1, n);
    return 0;
}