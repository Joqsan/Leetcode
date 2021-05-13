#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        int curr_sum = 0;
        int max_sum = INT32_MIN;
        
        for (int i = 0; i != nums.size(); ++i)
        {
            if (i < k)
                curr_sum += nums[i];
            else
            {
                max_sum = max(max_sum, curr_sum);
                curr_sum += nums[i] - nums[i-k];
            }
        }
        
        max_sum = max(max_sum, curr_sum);
        
        return double(max_sum) / k;
    }
};

int main(void)
{
    vector<int> nums{4,0,4,3,3};
    int k = 5;
    
    Solution sol = Solution();
    
    cout << sol.findMaxAverage(nums, k) << endl;
    
    return 0;
}
