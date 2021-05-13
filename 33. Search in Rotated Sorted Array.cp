#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    Solution(void) = default;
    
    int search(vector<int>& nums, int target)
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
        
        if (l != 0 && target >= nums[0])
        {
            r = l-1;
            l = 0;
        }
        else
            r = nums.size() - 1;

        while (l <= r)
        {
            int m = (l + r) / 2;

            if (target == nums[m])
                return m;

            if (target < nums[m])
                r = m-1;
            else if (target > nums[m])
                l = m+1;
        }

        return -1;
    }
};


int main(void)
{
    vector<int> nums{1};
    int target = 0;
    
    Solution sol = Solution();
    
    cout << sol.search(nums, target) << endl;
    
    return 0;
}

