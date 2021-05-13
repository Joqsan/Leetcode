#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    Solution(void) = default;
    
    void moveZeroes(vector<int>& nums)
    {
        int zeroPos = 0;
        int nonZeroPos = 0;
        int n = int(nums.size());
        
        while (zeroPos != n && nonZeroPos != n)
        {
            if (nums[nonZeroPos] == 0)
            {
                ++nonZeroPos;
                continue;
            }
            else if (nums[zeroPos] != 0)
            {
                ++zeroPos;
                continue;
            }
            else if (zeroPos < nonZeroPos)
                swap(nums[nonZeroPos++], nums[zeroPos++]);
            else
                nonZeroPos = zeroPos + 1;
        }
        
    }
};

int main(void)
{
    vector<int> nums{1,0,1,0,0,0};
    
    Solution sol = Solution();
    sol.moveZeroes(nums);
    
    for (auto v : nums)
        cout << v << " ";
    
    cout << endl;
    
    return 0;
}
