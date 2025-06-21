#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void tower(vector<string> &vec, int n, int num)
{
    if (n == num)
    {
        for (int i = 0; i < pow(2, n) - 1; i++)
        {
            cout << vec[i] << endl;
        }
    }
    else
    {
        if ((n + 1) % 2 == 0)
            vector<string> ans = {"1 2"};
        else if ((n + 1) % 2 == 0)
            vector<string> ans = {"1 3"};
        for (int i = 0; i < pow(2, n) - 1; i++)
        {
        }
        n++;
        tower(vec, n, num);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> vec = {"1 3"};
    tower(vec, 1, n);
}