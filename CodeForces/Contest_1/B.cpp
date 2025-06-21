#include <iostream>
using namespace std;

int ind_min(int arr[], int n)
{
    int min = arr[0];
    int indx = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            indx = i;
        }
    }
    return indx;
}

int ind_max(int arr[], int n)
{
    int min = arr[0];
    int indx = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min)
        {
            min = arr[i];
            indx = i;
        }
    }
    return indx;
}

int recur1(int n, int m, int a, int b, int cnt)
{
    int arr[4];
    if (m > b)
        arr[0] = (m - b) * n;
    if (b > 1)
        arr[1] = (b - 1) * n;
    if (n > a)
        arr[2] = (n - a) * m;
    if (a > 1)
        arr[3] = (a - 1) * m;
    int indx = ind_min(arr, 4);
}

int recur2(int n, int m, int a, int b, int cnt)
{
    int int arr[4];
    if (m > b)
        arr[0] = (m - b) * n;
    if (b > 1)
        arr[1] = (b - 1) * n;
    if (n > a)
        arr[2] = (n - a) * m;
    if (a > 1)
        arr[3] = (a - 1) * m;
    int indx = ind_min(arr, 4);
}

int main()
{
}