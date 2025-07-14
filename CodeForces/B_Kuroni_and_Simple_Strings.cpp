#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<vector<int>> result;

    while (true)
    {
        vector<int> open, close;

        // Step 1: Find positions of '(' from left and ')' from right
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                open.push_back(i);
        }
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == ')')
                close.push_back(i);
        }

        // Step 2: Pair them greedily
        vector<int> indices;
        int i = 0;
        while (i < open.size() && i < close.size() && open[i] < close[i])
        {
            indices.push_back(open[i]);
            indices.push_back(close[i]);
            i++;
        }

        if (indices.empty())
            break;

        // Sort and store 1-based indices
        sort(indices.begin(), indices.end());
        result.push_back(indices);

        // Step 3: Remove used characters from string
        string temp = "";
        int j = 0;
        for (int k = 0; k < s.size(); ++k)
        {
            if (j < indices.size() && k == indices[j])
            {
                j++;
            }
            else
            {
                temp += s[k];
            }
        }
        s = temp;
    }

    // Final output
    cout << result.size() << "\n";
    for (auto &group : result)
    {
        cout << group.size() << "\n";
        for (int idx : group)
        {
            cout << idx + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}
