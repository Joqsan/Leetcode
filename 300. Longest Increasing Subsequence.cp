#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    
    Solution(void) = default;
    
    int lengthOfLIS(vector<int>& nums)
    {
        int N = int(nums.size());
        vector<int> dp(N, -1);
        
        // dp[i] is the longest increasing subsequence
        // including i in that subsequence.
        int maxLIS = 0;
        dp[0] = 1;
        
        for (int k = 0; k != N; ++k)
        {
            int maxLenBefore = 0;
            for (int i = 0; i != k; ++i)
                if (nums[i] < nums[k])
                    maxLenBefore = max(dp[i], maxLenBefore);
            
            dp[k] = maxLenBefore + 1;
            
            maxLIS = max(maxLIS, dp[k]);
        }
        
        return maxLIS;
    }
};


int main(void)
{
    vector<int> nums{0, 8, 4, 12, 2};
    
    Solution sol = Solution();
    
    cout << sol.lengthOfLIS(nums) << endl;
    
    return 0;
}
