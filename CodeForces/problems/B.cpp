#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool calc(string l)
{
    int n = l.size();
    int sum = 1;
    for (int i = 1; i < n; i++)
    {
        if (l[i] == '(')
            sum++;
        else
            sum--;
        if (sum == 0 && i < n - 1)
            return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    string l;
    for (int i = 0; i < n; i++)
    {
        cin >> l;
        if (calc(l))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}