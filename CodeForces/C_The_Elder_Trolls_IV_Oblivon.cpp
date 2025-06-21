#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    long long x, y, z, k;
    cin >> x >> y >> z >> k;

    vector<long long> dims = {x, y, z};
    sort(dims.begin(), dims.end());

    vector<long long> cuts = {0, 0, 0};
    long long remaining_cuts = k;

    while (remaining_cuts > 0)
    {
        int best_dim = -1;
        long long min_cuts = -1;

        for (int i = 0; i < 3; ++i)
        {
            if (cuts[i] < dims[i] - 1)
            {
                if (best_dim == -1 || cuts[i] < min_cuts)
                {
                    min_cuts = cuts[i];
                    best_dim = i;
                }
            }
        }

        if (best_dim == -1)
        {
            break; // No more cuts possible
        }

        cuts[best_dim]++;
        remaining_cuts--;
    }

    long long result = (cuts[0] + 1) * (cuts[1] + 1) * (cuts[2] + 1);
    cout << result << endl;

    return 0;
}