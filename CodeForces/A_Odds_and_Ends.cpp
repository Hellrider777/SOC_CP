#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }

    if (n % 2 == 1 && vec[0] % 2 == 1 && vec[n - 1] % 2 == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
