#include <iostream>
#include <vector>
#include <algorithm>

// Use standard namespace for brevity in competitive programming contexts
using namespace std;

// Define long long for larger integer types
typedef long long ll;

// Modulo constant, a prime number often used in competitive programming
const ll MOD = 998244353;
// Maximum size for arrays, ensuring precomputed powers of 2 have enough capacity
const ll MAXN = 1e5 + 5;

// Array to store precomputed powers of 2 modulo MOD
ll pow2[MAXN];

/**
 * @brief Precomputes powers of 2 modulo MOD.
 * pow2[i] will store (2^i) % MOD.
 */
void precompute()
{
    pow2[0] = 1; // 2^0 = 1
    for (ll i = 1; i < MAXN; ++i)
    {
        // Calculate 2^i as (2 * 2^(i-1)) % MOD
        pow2[i] = (2LL * pow2[i - 1]) % MOD;
    }
}

// Global vectors and N to avoid passing them as arguments in recursive calls,
// which can be slightly faster in competitive programming.
vector<ll> vec1_global;
vector<ll> vec2_global;
vector<ll> ans_global;
ll N_global; // Stores the current 'n' for the test case

/**
 * @brief Solves the Max-Plus Convolution problem using a Divide and Conquer approach.
 * This function computes ans_global[i] for i in the range [i_low, i_high],
 * considering j (index for vec1_global) in the range [j_low, j_high].
 *
 * @param i_low The lower bound of the 'i' range for which ans_global is being computed.
 * @param i_high The upper bound of the 'i' range for which ans_global is being computed.
 * @param j_low The lower bound of the 'j' range to consider for optimal_j.
 * @param j_high The upper bound of the 'j' range to consider for optimal_j.
 */
void solve_max_plus_convolution(ll i_low, ll i_high, ll j_low, ll j_high)
{
    // Base case: If the range for 'i' is invalid, return.
    if (i_low > i_high)
    {
        return;
    }

    // Calculate the middle index for the current 'i' range.
    ll i_mid = i_low + (i_high - i_low) / 2;

    // Initialize the maximum value found for ans_global[i_mid] and its corresponding optimal 'j'.
    ll current_max_val = 0;
    ll optimal_j = -1; // Will be updated to a valid index within the loop

    // Determine the effective search range for 'j' for the current i_mid.
    // 'j' must be within [j_low, j_high] (inherited from parent recursion).
    // 'j' must also be <= i_mid (from the problem definition: j <= i).
    // 'i_mid - j' must be a valid index for vec2_global, i.e., 0 <= (i_mid - j) < N_global.
    // Since j <= i_mid, (i_mid - j) >= 0 is guaranteed.
    // Since j_low >= 0 and i_mid < N_global, (i_mid - j) will always be < N_global.
    // Thus, the effective upper bound for 'j' is min(j_high, i_mid).
    // The effective lower bound for 'j' is j_low.
    for (ll j = j_low; j <= min(j_high, i_mid); ++j)
    {
        // Calculate the two terms: pow2[vec1[j]] and pow2[vec2[i_mid - j]]
        ll pj = pow2[vec1_global[j]];
        ll qj = pow2[vec2_global[i_mid - j]];

        // Calculate their sum modulo MOD
        ll current_sum = (pj + qj) % MOD;

        // If the current sum is greater than the maximum found so far for ans_global[i_mid],
        // update the maximum value and the optimal 'j'.
        if (current_sum > current_max_val)
        {
            current_max_val = current_sum;
            optimal_j = j;
        }
    }

    // Store the computed maximum value for ans_global[i_mid]
    ans_global[i_mid] = current_max_val;

    // Recursively solve for the left half of the 'i' range.
    // The optimal 'j' for elements in [i_low, i_mid - 1] will be less than or equal to optimal_j.
    solve_max_plus_convolution(i_low, i_mid - 1, j_low, optimal_j);

    // Recursively solve for the right half of the 'i' range.
    // The optimal 'j' for elements in [i_mid + 1, i_high] will be greater than or equal to optimal_j.
    solve_max_plus_convolution(i_mid + 1, i_high, optimal_j, j_high);
}

int main()
{
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C stdio and disables synchronization.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Precompute powers of 2 once at the beginning.
    precompute();

    ll t;
    cin >> t; // Read the number of test cases

    // Process each test case
    for (ll ctr = 0; ctr < t; ctr++)
    {
        ll n;
        cin >> n; // Read the size of arrays for the current test case

        // Resize global vectors for the current test case to 'n' elements.
        // assign() is used to clear and resize, initializing with 0.
        vec1_global.assign(n, 0);
        vec2_global.assign(n, 0);
        ans_global.assign(n, 0);
        N_global = n; // Set the global 'n' for current test case

        // Read elements for vec1_global
        for (ll i = 0; i < n; i++)
        {
            cin >> vec1_global[i];
        }
        // Read elements for vec2_global
        for (ll i = 0; i < n; i++)
        {
            cin >> vec2_global[i];
        }

        // Call the divide and conquer function to compute the max-plus convolution.
        // The initial call covers the entire range of 'i' [0, n-1]
        // and the entire possible range of 'j' [0, n-1].
        solve_max_plus_convolution(0, n - 1, 0, n - 1);

        // Print the results for the current test case.
        // Use "\n" instead of endl for faster output, as endl flushes the buffer.
        for (ll i = 0; i < n; ++i)
        {
            cout << ans_global[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0; // Indicate successful program execution
}
