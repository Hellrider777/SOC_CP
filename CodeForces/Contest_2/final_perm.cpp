#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Check if the transformed vector is valid: all distinct modulo n
bool isValid(const vector<int> &perm, int n, vector<int> &result)
{
    set<int> seen;
    result.resize(n);
    for (int i = 0; i < n; i++)
    {
        result[i] = (perm[i] + i) % n;
        if (seen.count(result[i]))
        {
            return false;
        }
        seen.insert(result[i]);
    }
    return true;
}

// Check if permutation is identity
bool isIdentity(const vector<int> &perm)
{
    for (int i = 0; i < perm.size(); i++)
    {
        if (perm[i] != i)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    // Create initial permutation
    vector<int> permutation;
    for (int i = 0; i < n; i++)
    {
        permutation.push_back(i);
    }

    vector<int> result;
    bool found = false;

    do
    {
        if (isIdentity(permutation))
            continue; // skip identity permutation

        if (isValid(permutation, n, result))
        {
            found = true;
            break;
        }
    } while (next_permutation(permutation.begin(), permutation.end()));

    if (found)
    {
        // Print indices
        for (int i = 0; i < n; i++)
        {
            cout << i << " ";
        }
        cout << "\n";

        // Print permutation found
        for (auto x : permutation)
        {
            cout << x << " ";
        }
        cout << "\n";

        // Print transformed result
        for (auto x : result)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }

    return 0;
}
