#include <iostream>
using namespace std;

int turnsTo1(int x)
{
    int cnt = 0;
    while (x > 1)
    {
        x = (x + 1) / 2;
        cnt++;
    }
    return cnt;
}

int main()
{
    int t;
    cin >> t;
    int arr[t];
    int original_t = t; // Save the original t
    for (int i = 0; i < t; i++)
    {
        long long n, m, a, b;
        cin >> n >> m >> a >> b;
        // Fouad's position doesn't matter due to his ability to move freely after each cut
        int ans = max(turnsTo1(n), turnsTo1(m));
        arr[i] = ans; // Assign value to array
    }

    for (int i = 0; i < t; i++)
    {
        cout << arr[i] << endl;
    }
}
