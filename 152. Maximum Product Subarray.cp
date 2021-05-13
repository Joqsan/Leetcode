#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 
 This is Kadane's algorithm for multiplication.
 
 For the Maximum Sum Subarray, enough to keep track of
 the previous maximum sum curr_max. If curr_max + nums[i] < nums[i]
 then we have to reset the sum beginning at index i.
 
 
 For the Maximum Product Subarray we have to keep track not only
 of curr_max but of curr_min. Because
 
 curr_min < curr_max
 
 Then we can have either
 
 curr_min * nums[i] < curr_max * nums[i]
 
 or
 
 curr_min * nums[i] > curr_max * nums[i]
 
 And this maximum value has to be compared to nums[i].
 
 */

class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int global_max = INT32_MIN;
        
        int curr_max = 1;
        int curr_min = 1;
        
        for (int i = 0; i != nums.size(); ++i)
        {
            if (nums[i] < 0)
                swap(curr_max, curr_min);
            
            curr_max = max(nums[i], curr_max * nums[i]);
            curr_min = min(nums[i], curr_min * nums[i]);
            
            global_max = max(curr_max, global_max);
        }
        
        return global_max;
    }
};

int main(void)
{
    vector<int> nums{0, 0, -2,3,-4, 0, -5, -7, 0, 0, 0};
    
    Solution sol  = Solution();
    
    cout << sol.maxProduct(nums) << endl;
    
    return 0;
    
}
