#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        bool done = false;

        // Look for the rightmost pair with sum >= 10
        for (int i = n - 2; i >= 0; --i)
        {
            int a = s[i] - '0';
            int b = s[i + 1] - '0';
            if (a + b >= 10)
            {
                string sum = to_string(a + b);
                cout << s.substr(0, i) + sum + s.substr(i + 2) << endl;
                done = true;
                break;
            }
        }

        // If no such pair, reduce the first two digits
        if (!done)
        {
            int a = s[0] - '0';
            int b = s[1] - '0';
            string sum = to_string(a + b);
            cout << sum + s.substr(2) << endl;
        }
    }

    return 0;
}
