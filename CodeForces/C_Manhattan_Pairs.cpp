#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
typedef long long ll;

struct Point
{
    ll x, y;
    ll id;
};

// Manhattan distance between two points
ll manhattanDistance(const Point &a, const Point &b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// Global variables for DP approach
std::vector<Point> globalPoints;
std::unordered_map<int, std::pair<ll, std::vector<std::pair<int, int>>>> memo;

// Bitmask DP approach - exact optimal solution
std::pair<ll, std::vector<std::pair<int, int>>> solveBitmaskDP(int mask)
{
    if (__builtin_popcount(mask) == globalPoints.size())
    {
        return {0, {}};
    }

    if (memo.find(mask) != memo.end())
    {
        return memo[mask];
    }

    int first = -1;
    for (int i = 0; i < globalPoints.size(); i++)
    {
        if (!(mask & (1 << i)))
        {
            first = i;
            break;
        }
    }

    ll maxDist = -1;
    std::vector<std::pair<int, int>> bestPairing;

    for (int j = first + 1; j < globalPoints.size(); j++)
    {
        if (!(mask & (1 << j)))
        {
            int newMask = mask | (1 << first) | (1 << j);
            ll dist = manhattanDistance(globalPoints[first], globalPoints[j]);
            auto result = solveBitmaskDP(newMask);
            ll totalDist = dist + result.first;

            if (totalDist > maxDist)
            {
                maxDist = totalDist;
                bestPairing = result.second;
                bestPairing.insert(bestPairing.begin(), {globalPoints[first].id, globalPoints[j].id});
            }
        }
    }

    memo[mask] = {maxDist, bestPairing};
    return {maxDist, bestPairing};
}

// Backtracking approach - exact optimal for medium size
ll maxDistBacktrack = 0;
std::vector<std::pair<int, int>> bestPairingBacktrack;

void backtrack(std::vector<bool> &used, std::vector<std::pair<int, int>> &currentPairing,
               ll currentDist, int paired)
{
    int n = globalPoints.size();

    if (paired == n / 2)
    {
        if (currentDist > maxDistBacktrack)
        {
            maxDistBacktrack = currentDist;
            bestPairingBacktrack = currentPairing;
        }
        return;
    }

    int first = -1;
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            first = i;
            break;
        }
    }

    for (int j = first + 1; j < n; j++)
    {
        if (!used[j])
        {
            used[first] = used[j] = true;
            currentPairing.push_back({globalPoints[first].id, globalPoints[j].id});
            ll dist = manhattanDistance(globalPoints[first], globalPoints[j]);
            backtrack(used, currentPairing, currentDist + dist, paired + 1);
            used[first] = used[j] = false;
            currentPairing.pop_back();
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll t;
    std::cin >> t;

    while (t--)
    {
        ll n;
        std::cin >> n;

        std::vector<Point> points(n);
        for (ll i = 0; i < n; ++i)
        {
            std::cin >> points[i].x >> points[i].y;
            points[i].id = i + 1;
        }

        std::vector<std::pair<int, int>> finalPairing;

        if (n <= 12)
        {
            globalPoints = points;
            memo.clear();
            finalPairing = solveBitmaskDP(0).second;
        }
        else if (n <= 16)
        {
            globalPoints = points;
            maxDistBacktrack = 0;
            bestPairingBacktrack.clear();
            std::vector<bool> used(n, false);
            std::vector<std::pair<int, int>> currentPairing;
            backtrack(used, currentPairing, 0, 0);
            finalPairing = bestPairingBacktrack;
        }
        else
        {
            std::sort(points.begin(), points.end(), [](const Point &a, const Point &b)
                      { return (a.x + a.y) < (b.x + b.y); });
            for (ll i = 0; i < n / 2; ++i)
            {
                finalPairing.push_back({points[i].id, points[i + n / 2].id});
            }
        }

        for (auto &pair : finalPairing)
        {
            std::cout << pair.first << " " << pair.second << "\n";
        }
    }

    return 0;
}
