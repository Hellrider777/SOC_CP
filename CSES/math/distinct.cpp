#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> vec;
    int cnt = 0;
    int k;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        vec.insert(k);
        cnt++;
    }
    cout << vec.size();
}