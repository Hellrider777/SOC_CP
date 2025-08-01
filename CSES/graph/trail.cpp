#include <iostream>
#include <vector>

using namespace std;

int calc(int n, vector<int> &vec)
{
    if (n <= vec.size())
        return vec[n - 1];
    int cnt = 0;
    for (int i = 5; i < n; i *= 5)
    {
        cnt += n / i;
    }
    vec.push_back(cnt);
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    if (n != 5)
        cout << calc(n, vec);
    else
        cout << 1;
}