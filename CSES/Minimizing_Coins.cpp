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
    int n, x;
    cin >> n >> x;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int cnt = 0;
    int ind = n - 1;
    while (x > 0)
    {
        if (ind < 0)
            break;
        cnt += (x / vec[ind]);
        x -= cnt * vec[ind];
        ind--;
    }
    if (x != 0)
        cout << -1;
    else
        cout << cnt;
}