#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

/*
 
 Kadane's Algorith.
 
 Since we're finding the maximum absolute sum subarray
 that subarray comes from finding the minimum subarray
 and the maximum one. Then the answer is found after
 taking the absolute value of both.
 
 */
class Solution
{
public:
    int maxAbsoluteSum(vector<int>& nums)
    {
        int global_max = 0;
        int local_max = 0;
        int local_min = 0;
        
        for (auto v : nums)
        {
            local_min = min(v, v + local_min);
            local_max = max(v, v + local_max);
            global_max = max(global_max, max(abs(local_min), abs(local_max)));
        }
        
        return global_max;
    }
};

int main(void)
{
    vector<int> nums{2,-5,1,-4,3,-2};
    
    Solution sol = Solution();
    
    cout << sol.maxAbsoluteSum(nums) << endl;
    
    return 0;
}
