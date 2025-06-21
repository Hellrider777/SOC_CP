#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string l;
    char a;
    for (int i = 0; i < n; i++)
    {
        string flag = "NO";
        cin >> l;
        cin >> a;
        int s = l.size();
        for (int j = 0; j < s; j++)
        {
            if (l[j] == a)
            {
                if ((j % 2 == 0) && ((s - j - 1) % 2 == 0))
                {
                    flag = "YES";
                    break;
                }
            }
        }
        cout << flag << endl;
    }
}