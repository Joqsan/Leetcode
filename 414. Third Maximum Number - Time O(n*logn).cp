#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;


/*
 
 Complexity:
 - Time: O(n*logn)
 - Space: O(n)
 
 */
class Solution
{
public:
    int thirdMax(vector<int>& nums)
    {
        unordered_map<int, bool> visited;
        priority_queue<int> Q;
        
        if (nums.size() == 1)
            return nums[0];
        
        for (int i = 0; i != nums.size(); ++i)
            if (!visited[nums[i]])
            {
                visited[nums[i]] = true;
                Q.push(nums[i]);
            }
        
        int max = Q.top();
        for (int i = 0; !Q.empty() && i != 2; ++i)
            Q.pop();
        
        return (!Q.empty()) ? Q.top() : max;
    }
};


int main(void)
{
    vector<int> nums{2,2,3,1};
    
    Solution sol = Solution();
    
    cout << sol.thirdMax(nums) << endl;
    
    return 0;
}
