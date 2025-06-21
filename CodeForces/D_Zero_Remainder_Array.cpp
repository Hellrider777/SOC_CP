#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        unordered_map<int, int> countMap;
        for (int j = 0; j < a; j++)
        {
            int k;
            cin >> k;
            int rem = k % b;
            if (rem != 0)
            {
                int need = b - rem;
                countMap[need]++;
            }
        }

        long long ans = 0;
        for (auto &[key, freq] : countMap)
        {
            long long val = key + 1LL + (freq - 1LL) * b;
            ans = max(ans, val);
        }

        cout << ans << endl;
    }

    return 0;
}
