#include <vector>
#include <iostream>

using namespace std;


class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int l = 0;
        int r = nums.size()-1;
        int temp_m = 0;
        int m = 0;
        
        bool found = false;
        while (l <= r)
        {
            m = (l + r) / 2;
            
            if (nums[m] == target)
            {
                found = true;
                break;
            }
            
            if (nums[m] < target)
                l = m+1;
            if (target < nums[m])
                r = m-1;
        }
        
        l = temp_m = m;
        r = nums.size()-1;
        while (found && l <= r)
        {
            int n = (l + r) / 2;
            if (target < nums[n])
            {
                r = n-1;
            }
            if (target == nums[n])
            {
                l = n+1;
            }
            
        }
        
        m = r;
        r = temp_m; // to find lower limit
        l = 0; // to find lower limit
        while (found && l <= r)
        {
            int n = (l + r) / 2;
            
            if (nums[n] < target)
                l = n+1;
            if (target == nums[n])
                r = n-1;
        }
        
        if (found)
            return vector<int>{l, m};
        else
            return vector<int>{-1, -1};
    }
};

int main(void)
{
    vector<int> nums{5,7,7,8,8,10};
    int target = 7;
    Solution sol = Solution();
    
    auto res = sol.searchRange(nums, target);
    
    for (auto v : res)
        cout << v << " ";
    cout << endl;
    
    return 0;
}
