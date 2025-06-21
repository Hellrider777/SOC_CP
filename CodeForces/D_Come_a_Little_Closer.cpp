#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

long long calculate_extended_area(long long min_x, long long max_x, long long min_y, long long max_y, int num_monsters)
{
    if (num_monsters == 0)
        return 0;
    long long width = max_x - min_x + 1;
    long long height = max_y - min_y + 1;
    if (width * height < (num_monsters + 1))
    {
        if (width >= height)
            width++;
        else
            height++;
        return width * height;
    }
    return width * height;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<long long, long long>> monsters(n);
        long long min_x1 = LLONG_MAX, min_x2 = LLONG_MAX;
        long long max_x1 = LLONG_MIN, max_x2 = LLONG_MIN;
        long long min_y1 = LLONG_MAX, min_y2 = LLONG_MAX;
        long long max_y1 = LLONG_MIN, max_y2 = LLONG_MIN;

        for (int i = 0; i < n; ++i)
        {
            cin >> monsters[i].first >> monsters[i].second;
            long long x = monsters[i].first;
            long long y = monsters[i].second;

            if (x < min_x1)
            {
                min_x2 = min_x1;
                min_x1 = x;
            }
            else if (x < min_x2)
                min_x2 = x;
            if (x > max_x1)
            {
                max_x2 = max_x1;
                max_x1 = x;
            }
            else if (x > max_x2)
                max_x2 = x;
            if (y < min_y1)
            {
                min_y2 = min_y1;
                min_y1 = y;
            }
            else if (y < min_y2)
                min_y2 = y;
            if (y > max_y1)
            {
                max_y2 = max_y1;
                max_y1 = y;
            }
            else if (y > max_y2)
                max_y2 = y;
        }

        if (n == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        if (n == 1)
        {
            cout << 1 << "\n";
            continue;
        }

        long long min_cost = calculate_extended_area(min_x1, max_x1, min_y1, max_y1, n);

        for (int i = 0; i < n; ++i)
        {
            long long current_min_x = (monsters[i].first == min_x1) ? min_x2 : min_x1;
            long long current_max_x = (monsters[i].first == max_x1) ? max_x2 : max_x1;
            long long current_min_y = (monsters[i].second == min_y1) ? min_y2 : min_y1;
            long long current_max_y = (monsters[i].second == max_y1) ? max_y2 : max_y1;
            long long current_cost = calculate_extended_area(current_min_x, current_max_x, current_min_y, current_max_y, n - 1);
            min_cost = min(min_cost, current_cost);
        }

        cout << min_cost << "\n";
    }

    return 0;
}