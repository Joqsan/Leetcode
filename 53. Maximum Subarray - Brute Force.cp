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
        vector<vector<int>> dp(N, vector<int>(N));
        int max_sum = INT32_MIN;
        
        for (int i = 0; i != N;++i)
        {
            dp[i][i] = nums[i];
            max_sum = max(max_sum, nums[i]);
        }
        
        for (int j = 1; j != N; ++j)
            for (int i = 0; i != N-j; ++i)
            {
                int start = i;
                int end = i+j;
                dp[start][end] = dp[start][end-1] + nums[end];
                max_sum = max(max_sum, dp[start][end]);
            }
        
        return max_sum;
    }
};

int main(void)
{
    vector<int> nums{-1,1,2,1};
    Solution sol = Solution();
    
    cout << sol.maxSubArray(nums) << endl;
    
    return 0;
}
