#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int N = nums.size();
        
        int local_max = 0;
        int global_max = INT32_MIN;
        
        for (int i = 0; i != N; ++i)
        {
            local_max = max(nums[i], nums[i] + local_max);
            
            if (local_max > global_max)
                global_max = local_max;
        }
        
        return global_max;
    }
};

int main(void)
{
    vector<int> nums{-1,1,2,1};
    Solution sol = Solution();
    
    cout << sol.maxSubArray(nums) << endl;
    
    return 0;
}
