#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX = 1e6;
    vector<bool> is_prime(MAX + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= MAX; j += i)
                is_prime[j] = false;
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        ll num;
        cin >> num;
        if (num <= MAX && is_prime[num])
        {
            cout << 2 << "\n";
            continue;
        }

        ll ans = 1;
        ll temp = num;
        for (ll i = 2; i * i <= temp; ++i)
        {
            if (is_prime[i] && num % i == 0)
            {
                int cnt = 0;
                while (num % i == 0)
                {
                    num /= i;
                    cnt++;
                }
                ans *= (cnt + 1);
            }
        }

        // If anything left of num > 1, it must be a prime factor
        if (num > 1)
            ans *= 2;

        cout << ans << "\n";
    }
}
