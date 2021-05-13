#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

/*
 The same approach as 53. Maximum Subarray:
 Kadane's algorithm is applied to the
 array of adjacent differences.
 
 Complexity: O(n) for calculating the adjacent
 differences + O(n) of Kadane's algorithm.
 */
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int N = prices.size();
        
        for (int i = N-1; i != 0; --i)
            prices[i] -= prices[i-1];
        
        int local_max = 0;
        int global_max = INT32_MIN;
        
        
        for (int i = 1; i != N; ++i)
        {
            local_max = max(prices[i], prices[i] + local_max);
            
            if (local_max > global_max)
                global_max = local_max;
        }
        
        if (global_max <= 0)
            return 0;
        else
            return global_max;
    }
};


int main(void)
{
    vector<int> nums{7,6,4,3,1};
    
    Solution sol = Solution();
    
    cout << sol.maxProfit(nums) << endl;
    
//    cout << nums.size() << endl;
//
//    adjacent_difference(nums.begin(), nums.end(), nums.begin());
//
//    cout << nums.size() << endl;
//
//    for (auto v : nums)
//        cout << v << " ";
//    cout << endl;
    
    return 0;
}
