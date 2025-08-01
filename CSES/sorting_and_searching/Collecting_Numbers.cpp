#include <iostream>
#include <vector>
using namespace std;

int cnt(const vector<int> &pos)
{
    int rounds = 1;
    int n = pos.size() - 1; // Because pos[0] is unused

    for (int i = 2; i <= n; i++)
    {
        if (pos[i] < pos[i - 1])
        {
            rounds++;
        }
    }

    return rounds;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    vector<int> pos(n + 1); // pos[i] = index of number i in vec

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        pos[vec[i]] = i;
    }

    cout << cnt(pos) << endl;
    return 0;
}
