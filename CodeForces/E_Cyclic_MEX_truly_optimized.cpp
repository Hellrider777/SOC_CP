#include <iostream>
#include <vector>
#include <algorithm>

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
        vector<int> vec(n);
        
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        
        int max_sum = 0;
        int best_shift = 0;
        int theoretical_max = n * (n + 1) / 2;
        
        // Smart approach: Focus on rotations that put small numbers first
        vector<int> priority_shifts;
        
        // Add rotation that puts each small number at the beginning
        for (int val = 0; val < min(n, 10); val++)
        {
            for (int i = 0; i < n; i++)
            {
                if (vec[i] == val)
                {
                    priority_shifts.push_back(i);
                    break;
                }
            }
        }
        
        // Remove duplicates
        sort(priority_shifts.begin(), priority_shifts.end());
        priority_shifts.erase(unique(priority_shifts.begin(), priority_shifts.end()), priority_shifts.end());
        
        // Try priority shifts first
        for (int shift : priority_shifts)
        {
            vector<bool> present(n + 1, false);
            int mex = 0;
            int current_sum = 0;
            
            for (int i = 0; i < n; i++)
            {
                int element = vec[(i + shift) % n];
                
                if (element < n)
                {
                    present[element] = true;
                }
                
                while (mex <= n && present[mex])
                {
                    mex++;
                }
                
                current_sum += mex;
            }
            
            if (current_sum > max_sum)
            {
                max_sum = current_sum;
                best_shift = shift;
            }
            
            if (max_sum == theoretical_max)
            {
                break;
            }
        }
        
        // If we didn't find the theoretical maximum, try remaining rotations
        if (max_sum < theoretical_max)
        {
            for (int shift = 0; shift < n; shift++)
            {
                // Skip if already tried
                if (find(priority_shifts.begin(), priority_shifts.end(), shift) != priority_shifts.end())
                    continue;
                
                vector<bool> present(n + 1, false);
                int mex = 0;
                int current_sum = 0;
                
                for (int i = 0; i < n; i++)
                {
                    int element = vec[(i + shift) % n];
                    
                    if (element < n)
                    {
                        present[element] = true;
                    }
                    
                    while (mex <= n && present[mex])
                    {
                        mex++;
                    }
                    
                    current_sum += mex;
                }
                
                if (current_sum > max_sum)
                {
                    max_sum = current_sum;
                    best_shift = shift;
                }
                
                if (max_sum == theoretical_max)
                {
                    break;
                }
            }
        }
        
        cout << max_sum << '\n';
        cout << "Best rotation: ";
        for (int i = 0; i < n; i++)
        {
            cout << vec[(i + best_shift) % n] << " ";
        }
        cout << '\n';
    }
    
    return 0;
} 