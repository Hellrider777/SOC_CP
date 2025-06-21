#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

ll n, m, k;

// Checks how much gold can be collected from explosion centered at (cx, cy)
ll evaluate_explosion(const vector<string> &grid, ll cx, ll cy)
{
    ll gold = 0;
    bool valid = true;

    for (ll i = cx - k; i <= cx + k; ++i)
    {
        for (ll j = cy - k; j <= cy + k; ++j)
        {
            if (i < 0 || i >= n || j < 0 || j >= m)
                continue;
            if (grid[i][j] == 'g')
            {
                if (i == cx - k || i == cx + k || j == cy - k || j == cy + k)
                {
                    gold++;
                }
                else
                {
                    valid = false; // destroys inner gold
                }
            }
        }
    }

    return valid ? gold : 0;
}

// Applies the explosion: sets everything in the square to '.'
void apply_explosion(vector<string> &grid, ll cx, ll cy)
{
    for (ll i = cx - k; i <= cx + k; ++i)
    {
        for (ll j = cy - k; j <= cy + k; ++j)
        {
            if (i >= 0 && i < n && j >= 0 && j < m)
            {
                grid[i][j] = '.';
            }
        }
    }
}

ll solve_case(vector<string> grid)
{
    ll total_gold = 0;

    while (true)
    {
        ll max_gold = 0, best_x = -1, best_y = -1;

        for (ll i = 0; i < n; ++i)
        {
            for (ll j = 0; j < m; ++j)
            {
                if (grid[i][j] == '.')
                {
                    ll collected = evaluate_explosion(grid, i, j);
                    if (collected > max_gold)
                    {
                        max_gold = collected;
                        best_x = i;
                        best_y = j;
                    }
                }
            }
        }

        if (max_gold == 0)
            break;

        total_gold += max_gold;
        apply_explosion(grid, best_x, best_y);
    }

    return total_gold;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        vector<string> grid(n);
        for (ll i = 0; i < n; ++i)
        {
            cin >> grid[i];
        }

        cout << solve_case(grid) << '\n';
    }

    return 0;
}
