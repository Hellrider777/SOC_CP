#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void merge(vector<long long> &arr, long long left,
           long long mid, long long right)
{
    long long n1 = mid - left + 1;
    long long n2 = right - mid;

    vector<long long> L(n1), R(n2);

    for (long long i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (long long j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    long long i = 0, j = 0;
    long long k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<long long> &arr, long long left, long long right)
{
    if (left >= right)
        return;

    long long mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        long long k;
        cin >> k;
        vector<long long> vec(4 * k, 0);
        for (long long j = 0; j < (4 * k); j++)
        {
            cin >> vec[j];
        }
        sort(vec.begin(), vec.end());
        bool f = true;
        for (long long j = 0; j < (4 * k); j += 2)
        {
            if (vec[j] != vec[j + 1])
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            long long prod = vec[0] * vec[(4 * k) - 1];
            for (long long i = 2; i < 2 * k - 1; i += 2)
            {
                if ((vec[i] * vec[4 * k - 1 - i]) != prod)
                {
                    f = false;
                    break;
                }
            }
        }
        if (f)
            cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
        }
    }
}