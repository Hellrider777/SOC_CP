#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
typedef long long ll;

int recur(map<int, int> mp, int ctr, int x)
{
    for (auto i : mp)
    {
        if(mp[i] <=x){
            
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x;
    cin >> n >> x;
    map<int, int> mp;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int k;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        mp[k] = vec[i];
    }
    int ctr = 0;
    cout << recur(mp, ctr, x);
}