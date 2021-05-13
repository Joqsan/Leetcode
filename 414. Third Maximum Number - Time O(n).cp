#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;


/*
 
 Complexity:
 - Time: O(n)
 - Space: O(1)
 
 */
class Solution
{
public:
    int thirdMax(vector<int>& nums)
    {
        long max1 = LONG_MIN;
        long max2 = LONG_MIN;
        long max3 = LONG_MIN;
        
        for (auto c : nums)
        if (c != max1 && c != max2 && c != max3)
        {
            if (c > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = c;
            }
            else if (c > max2)
            {
                max3 = max2;
                max2 = c;
            }
            else if (c > max3)
                max3 = c;
        }
        
        return (max3 == LONG_MIN) ? max1 : max3;
    }
};


int main(void)
{
    vector<int> nums{2,2,3,1};
    
    Solution sol = Solution();
    
    cout << sol.thirdMax(nums) << endl;
    
    return 0;
}
