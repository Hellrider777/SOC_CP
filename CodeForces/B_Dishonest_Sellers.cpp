#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void merge(vector<int> &arr, int left,
           int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back
    // into arr[left..right]
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

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> vec1(n, 0);
    vector<int> vec2(n, 0);
    int k;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> vec1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        vec2[i] = vec1[i] - k;
        sum += k;
    }
    mergeSort(vec2, 0, n - 1);
    int i = 0;
    while (true)
    {
        if (i < m || (i >= m && vec2[i] < 0))
        {
            sum += vec2[i];
            i++;
        }
        else
        {
            break;
        }
    }

    cout << sum;
}
