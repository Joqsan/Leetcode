#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


/*
 
 Maximum subarray is not circular. Then Use Kadane's Algorithm
 
 Maximum subarray is circular. Then some part of it is a prefix
 of A and the other a suffix.
 
 Then we want
 
 max(prefix_i + suffix_i) = max(total_sum - subarray_i)
                          = total_sum + max(-subarray_i)
                          = total_sum - min(subarray_i)
 
 So in the second case the maximum circular sum array is equal to the
 sum of the array minus the minimum subarray sum
 */

class Solution
{
public:
    int maxSubarraySumCircular(vector<int>& A)
    {
        int local_max = 0;
        int local_min = 0;
        int global_max = INT32_MIN;
        int global_min = INT32_MAX;
        int sum = 0;
        
        for (auto n : A)
        {
            sum += n;
            local_max = max(n, n + local_max);
            local_min = min(n, n + local_min);
            
            global_max = max(global_max, local_max);
            global_min = min(global_min, local_min);
        }
        
        return max(global_max, sum - global_min);
    }
};

int main(void)
{
    vector<int> nums{3,-1,2,-1};
    Solution sol = Solution();
    
    cout << sol.maxSubarraySumCircular(nums) << endl;
    
    return 0;
}
