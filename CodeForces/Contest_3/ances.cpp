#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool check(string a, string b)
{

    if (b.length() < a.length())
        return false;

    int i = b.length() - a.length();

    for (int j = 0; j < a.length(); j++)
    {
        if (b[i + j] != a[j])
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<string> vec;
    string l;
    for (int i = 0; i < n; i++)
    {
        cin >> l;
        vec.push_back(l);
    }
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        found = true;
        for (int j = 0; j < n; j++)
        {
            if (!check(vec[i], vec[j]))
            {
                found = false;
                break;
            }
        }
        if (found == true)
        {
            cout << vec[i];
            break;
        }
    }
    if (found == false)
        cout << "Not found";
}