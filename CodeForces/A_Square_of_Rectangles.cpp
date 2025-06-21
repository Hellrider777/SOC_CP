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
    int l1, b1, l2, b2, l3, b3;
    while (n--)
    {

        bool f = false;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

        // First pair: (l1, b1) and (l2, b2)
        if (l1 == l2 || b1 == b2)
        {
            if (l1 == l2)
            {
                int b = b1 + b2;
                if (l3 == l1 && b + b3 == l1)
                    f = true;
                if (b == b3 && (l3 + l1 == b))
                    f = true;
            }
            if (b1 == b2)
            {
                int l = l1 + l2;
                if (b3 == b1 && l + l3 == b1)
                    f = true;
                if (l == l3 && (b1 + b3 == l))
                    f = true;
            }
        }

        // Second pair: (l1, b1) and (l3, b3)
        if (!f && (l1 == l3 || b1 == b3))
        {
            if (l1 == l3)
            {
                int b = b1 + b3;
                if (l2 == l1 && (b + b2 == l1))
                    f = true;
                if (b == b2 && (l2 + l1 == b))
                    f = true;
            }
            if (b1 == b3)
            {
                int l = l1 + l3;
                if (b2 == b1 && l + l2 == b1)
                    f = true;
                if (l == l2 && (b1 + b2 == l))
                    f = true;
            }
        }

        // Third pair: (l2, b2) and (l3, b3)
        if (!f && (l2 == l3 || b2 == b3))
        {
            if (l2 == l3)
            {
                int b = b2 + b3;
                if (l1 == l2 && b + b1 == l2)
                    f = true;
                if (b == b1 && (l1 + l2 == b))
                    f = true;
            }
            if (b2 == b3)
            {
                int l = l2 + l3;
                if (b1 == b2 && l + l1 == b2)
                    f = true;
                if (l == l1 && (b1 + b2 == l))
                    f = true;
            }
        }

        cout << (f ? "YES\n" : "NO\n");
    }
    return 0;
}