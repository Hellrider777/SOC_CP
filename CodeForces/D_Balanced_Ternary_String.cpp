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
    int n;
    cin >> n;
    string l;
    vector<int> vec0;
    vector<int> vec1;
    vector<int> vec2;
    cin >> l;
    for (int i = 0; i < n; i++)
    {
        if (l[i] == '0')
            vec0.push_back(i);
        if (l[i] == '1')
            vec1.push_back(i);
        if (l[i] == '2')
            vec2.push_back(i);
    }
    if (vec0.size() >= (n / 3))
    {
        if (vec1.size() >= (n / 3))
        {
            int s1 = vec1.size();
            for (int i = 0; i < (s1 - (n / 3)); i++)
            {
                vec2.push_back(vec1.back());
                vec1.pop_back();
            }
            int s2 = vec0.size();
            for (int i = 0; i < (s2 - (n / 3)); i++)
            {
                vec2.push_back(vec0.back());
                vec0.pop_back();
            }
        }
        else if (vec2.size() >= (n / 3))
        {
            int s2 = vec0.size();
            for (int i = 0; i < (s2 - (n / 3)); i++)
            {
                vec1.push_back(vec0.back());
                vec0.pop_back();
            }
            int s1 = vec2.size();
            int idx = 0;
            for (int i = 0; i < (s1 - (n / 3)); i++)
            {
                vec1.push_back(vec2[idx++]);
                vec2[idx - 1] = -1;
            }
        }
        else
        {
            int s1 = vec2.size();
            for (int i = 0; i < ((n / 3) - s1); i++)
            {
                vec2.push_back(vec0.back());
                vec0.pop_back();
            }
            int s2 = vec1.size();
            for (int i = 0; i < ((n / 3) - s2); i++)
            {
                vec1.push_back(vec0.back());
                vec0.pop_back();
            }
        }
    }
    else
    {
        if ((vec1.size() >= (n / 3)) && (vec2.size() >= (n / 3)))
        {
            int s1 = vec1.size();
            int idx = 0;
            for (int i = 0; i < (s1 - (n / 3)); i++)
            {
                vec0.push_back(vec1[idx++]);
                vec1[idx - 1] = -1;
            }
            s1 = vec2.size();
            idx = 0;
            for (int i = 0; i < (s1 - (n / 3)); i++)
            {
                vec0.push_back(vec2[idx++]);
                vec2[idx - 1] = -1;
            }
        }
        else if (vec1.size() >= (n / 3))
        {
            int s1 = vec0.size();
            int idx = 0;
            for (int i = 0; i < ((n / 3) - s1); i++)
            {
                vec0.push_back(vec1[idx++]);
                vec1[idx - 1] = -1;
            }
            int s2 = vec2.size();
            for (int i = 0; i < ((n / 3) - s2); i++)
            {
                vec2.push_back(vec1.back());
                vec1.pop_back();
            }
        }
        else
        {
            int s1 = vec0.size();
            int idx = 0;
            for (int i = 0; i < ((n / 3) - s1); i++)
            {
                vec0.push_back(vec2[idx++]);
            }
            s1 = vec1.size();
            for (int i = 0; i < ((n / 3) - s1); i++)
            {
                vec1.push_back(vec2[idx++]);
            }
        }
    }

    for (int k : vec2)
        if (k > -1)
            l[k] = '2';
    for (int j : vec1)
        if (j > -1)
            l[j] = '1';
    for (int i : vec0)
        if (i > -1)
            l[i] = '0';

    cout << l;
}