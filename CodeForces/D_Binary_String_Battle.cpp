#include <iostream>
#include <string>
#include <algorithm> // for std::count

using namespace std;

// Check if a block of at least k zeros exists
bool has_zero_block(const string &s, int k)
{
    int cnt = 0;
    for (char c : s)
    {
        if (c == '0')
        {
            cnt++;
            if (cnt >= k)
                return true;
        }
        else
        {
            cnt = 0;
        }
    }
    return false;
}

// Bob's move: turn one block of k zeros into 1s
void bob_move(string &s, int k)
{
    int cnt = 0;
    int start = -1;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '0')
        {
            if (cnt == 0)
                start = i;
            cnt++;
            if (cnt == k)
            {
                for (int j = start; j < start + k; ++j)
                    s[j] = '1';
                return;
            }
        }
        else
        {
            cnt = 0;
        }
    }
}

// Alice removes up to k 1s from anywhere
void alice_move(string &s, int k)
{
    for (int i = 0; i < s.size() && k > 0; ++i)
    {
        if (s[i] == '1')
        {
            s[i] = '0';
            k--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        
        // Count initial number of ones
        int ones = 0;
        for (char c : s) {
            if (c == '1') ones++;
        }
        
        // Key insight: Alice wins if ones <= k + (n-k-1)/2
        // This is because:
        // 1. Alice can eliminate up to k ones per turn
        // 2. Bob can create at most k ones per turn, but only in consecutive positions
        // 3. The maximum sustainable ones Bob can maintain is limited by string structure
        
        // If ones <= k, Alice wins immediately
        if (ones <= k) {
            cout << "Alice\n";
        }
        // Alice wins if ones <= k + floor((n-k-1)/2)
        // This accounts for the positions Bob cannot effectively use
        else if (ones <= k + (n - k - 1) / 2) {
            cout << "Alice\n";
        }
        else {
            cout << "Bob\n";
        }
    }
    
    return 0;
}
