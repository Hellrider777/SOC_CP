#include <iostream>
#include <vector>

using namespace std;

bool ans(int a, int b)
{
    int sum = a + b;
    if (sum % 3 != 0)
        return false;
    int k = sum / 3;
    if (a - k >= 0 && a - k <= k)
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (ans(a, b))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}