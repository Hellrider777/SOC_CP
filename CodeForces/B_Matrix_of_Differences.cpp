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
    int k;
    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;
        vector<vector<int>> ans;
        vector<int> vec(n, 0);
        int st = 1;
        int end = n * n;
        int curr = 1;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                for (int i = 0; i < n; i++)
                {
                    vec[i] = curr;
                    if (st == curr)
                    {
                        st++;
                        curr = end;
                    }
                    else
                    {
                        end--;
                        curr = st;
                    }
                }
            }
            else
            {
                for (int i = n - 1; i >= 0; i--)
                {
                    vec[i] = curr;
                    if (st == curr)
                    {
                        st++;
                        curr = end;
                    }
                    else
                    {
                        end--;
                        curr = st;
                    }
                }
            }
            ans.push_back(vec);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
}