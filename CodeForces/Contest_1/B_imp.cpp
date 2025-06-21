#include <iostream>
using namespace std;

int ind(int arr[], int n)
{
    int max = arr[0];
    int indx = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            indx = i;
        }
    }
    return indx;
}

int recur(int n, int m, int a, int b, int cnt)
{
    if (n == 1 && m == 1)
    {
        return cnt;
    }
    int arr[4];
    if (m > b)
        arr[0] = (m - b) * n;
    else
        arr[0] = 0;
    if (b > 1)
        arr[1] = (b - 1) * n;
    else
        arr[1] = 0;
    if (n > a)
        arr[2] = (n - a) * m;
    else
        arr[2] = 0;
    if (a > 1)
        arr[3] = (a - 1) * m;
    else
        arr[3] = 0;
    int indx = ind(arr, 4);

    if (indx == 0)
        return recur(n, b, (n / 2) + 1, (b / 2) + 1, cnt + 1);
    if (indx == 1)
        return recur(n, m - b + 1, (n / 2) + 1, (m - b + 3) / 2, cnt + 1);
    if (indx == 2)
        return recur(a, m, (a / 2) + 1, (m / 2) + 1, cnt + 1);
    if (indx == 3)
        return recur(n - a + 1, m, (n - a + 3) / 2, (m / 2) + 1, cnt + 1);
}

int main()
{
    int n, m, a, b;
    int k;
    cin >> k;
    int arr[k];
    for (int i = 0; i < k; i++)
    {

        cin >> n >> m;
        cin >> a >> b;
        arr[i] = recur(n, m, a, b, 0);
    }

    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << endl;
    }
}