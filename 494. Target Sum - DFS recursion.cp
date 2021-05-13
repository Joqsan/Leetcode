#include <vector>
#include <iostream>

using namespace std;




class Solution
{
public:
    
    int N;
    int counter = 0;
    void DFS(int sum, int curr_idx, const int& target, vector<int>& nums)
    {
        if (curr_idx == N-1)
        {
            if (sum == target)
                ++counter;
            else
                return ;
        }
        else
        {
            DFS(sum + nums[curr_idx+1], curr_idx+1, target, nums);
            DFS(sum - nums[curr_idx+1], curr_idx+1, target, nums);
        }
    }
    
    int findTargetSumWays(vector<int>& nums, int target)
    {
        N = nums.size();
        
        DFS(0, -1, target, nums);
        
        
        return counter;
    }
};

int main(void)
{
    vector<int> nums{1,1,1,1,1};
    int target = 10;
    
    Solution sol = Solution();
    
    cout << sol.findTargetSumWays(nums, target) << endl;
    
    return 0;
}
