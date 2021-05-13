#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    Solution(void) = default;
    
    int findMin(vector<int>& nums)
    {
        int l = 0;
        int r = int(nums.size()) - 1;
        
        while (nums[l] > nums[r])
        {
            int m = (l + r) / 2;
            
            if (nums[m] > nums[r])
                l = m+1;
            else
                r = m;
        }
        
        return nums[l];
    }
};


int main(void)
{
    vector<int> nums{11,13,15,17};
    
    Solution sol = Solution();
    
    cout << sol.findMin(nums) << endl;
    
    return 0;
}

