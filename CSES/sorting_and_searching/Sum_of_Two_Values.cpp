#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x;
    cin >> n >> x;
    map<int, int> value_to_index;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (x >= arr[i])
        {
            int complement = x - arr[i];
            if (value_to_index.count(complement))
            {
                // Found the pair
                cout << value_to_index[complement] + 1 << " " << i + 1 << "\n";
                return 0;
            }
        }
        value_to_index[arr[i]] = i;
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
