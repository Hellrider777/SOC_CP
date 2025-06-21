#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // Handle n=1 separately (always YES if a[0] == 0, else NO)
        if (n == 1)
        {
            cout << (a[0] == 0 ? "YES\n" : "NO\n");
            continue;
        }

        // Build the coefficient matrix for first two equations:
        // a1 = x*1 + y*n
        // a2 = x*2 + y*(n-1)
        //
        // Matrix:
        // | 1   n     |
        // | 2   n - 1 |
        //
        // Solve:
        // det = 1*(n-1) - 2*n = n-1 - 2n = - (n+1)
        //
        // x = (a1*(n-1) - a2*n) / det
        // y = (1*a2 - 2*a1) / det

        long long det = -(n + 1);
        long long numerator_x = a[0] * (n - 1) - a[1] * n;
        long long numerator_y = a[1] - 2 * a[0];

        // Check det divides numerator exactly
        if (det == 0)
        {
            // Should not happen since n>=2, but just in case:
            cout << "NO\n";
            continue;
        }
        if (numerator_x % det != 0 || numerator_y % det != 0)
        {
            cout << "NO\n";
            continue;
        }

        long long x = numerator_x / det;
        long long y = numerator_y / det;

        // x, y must be >= 0
        if (x < 0 || y < 0)
        {
            cout << "NO\n";
            continue;
        }

        // Verify for all i:
        // a[i] == x*(i+1) + y*(n - i)
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            long long val = x * (i + 1) + y * (n - i);
            if (a[i] != val)
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
