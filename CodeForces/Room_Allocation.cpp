#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        vec[a - 1]++;
        vec[b - 1]--;
    }
    int max = vec[0];
    for (int i = 1; i < n; i++)
    {
        vec[i] += vec[i - 1];
        max = max > vec[i] ? max : vec[i];
    }
    cout << max;
}