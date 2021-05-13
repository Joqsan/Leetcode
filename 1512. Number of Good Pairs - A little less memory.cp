#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

/*
 
 Complexity:
 - Time: O(n)
 - Space: O(2*n)
 
 */
class Solution
{
public:
    int numIdenticalPairs(vector<int>& nums)
    {
        
        unordered_map<int, int> counter;
        
        int n_pairs = 0;
        for (auto n : nums)
            n_pairs = n_pairs + counter[n]++;
        
        return n_pairs;
    }
};

int main(void)
{
    vector<int> nums{1,2,3};
    
    Solution sol = Solution();
    
    cout << sol.numIdenticalPairs(nums) << endl;
    
    return 0;
}
