#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int p_infty = 11e4;
int n_infty = -11e4;

class Solution
{
public:
    
    Solution(void) = default;
    
    int lengthOfLIS(vector<int>& nums)
    {
        int N = int(nums.size());
        
        if (N == 1)
            return 1;
        
        vector<int> seq(N+1, p_infty);
        int maxLen = 0;
        
        seq[0] = n_infty;
        
        for (int k = 0; k != N; ++k)
        {
            auto it = lower_bound(seq.begin(), seq.begin()+1+maxLen, nums[k]);
            
            seq[it - seq.begin()] = nums[k];
            
            maxLen = max(maxLen, int(it - seq.begin()));
        }
        
        return maxLen;
    }
};


int main(void)
{
    vector<int> nums{-2,-1};
    
    Solution sol = Solution();
    
    cout << sol.lengthOfLIS(nums) << endl;
    
    return 0;
}
