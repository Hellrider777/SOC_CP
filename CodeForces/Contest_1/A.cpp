#include <iostream>
using namespace std;

bool check(int n)
{
    int flag = 0;
    int arr[100];

    int ctr = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
            ctr++;
    }
    if (ctr == n || ctr == 0)
        flag = 1;

    if (n == 2)
    {
        if (arr[0] == arr[1])
        {
            flag = 1;
        }
    }

    for (int k = 1; k < n - 1; k++)
    {

        if (arr[k] == 0)
        {
            if (arr[k - 1] == 0 || arr[k + 1] == 0)
            {
                flag = 1;
                break;
            }
        }
    }

    if (flag == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int n;
    cin >> n;
    int k;
    int ans[n];
    for (int i = 0; i < n; i++)
    {
        cin >> k;

        if (check(k))
        {
            ans[i] = 1;
        }
        else
        {
            ans[i] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (ans[i] == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}