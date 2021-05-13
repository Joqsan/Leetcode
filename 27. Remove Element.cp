#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    Solution(void) = default;
    
    int removeElement(vector<int>& nums, int val)
    {
        int l = -1;
        int r = int(nums.size()) - 1;
        
        while (l < r)
        {
            if (nums[r] == val)
            {
                --r;
                continue;
            }
            
            ++l;
            if (nums[l] == val)
                swap(nums[l], nums[r--]);
        }
        
        return l+1;
        
    }
};

int main(void)
{
    vector<int> nums{};
    int val = 1;
    
    Solution sol = Solution();
    
    cout << sol.removeElement(nums, val) << endl;
    
    return 0;
}
