#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        vector<bool> visited(nums.size(), false);
        vector<int> ans;
        
        for (int i = 0; i != nums.size(); ++i)
        {
            if (!visited[nums[i]])
                visited[nums[i]] = true;
            else
                ans.push_back(nums[i]);
        }
        
        int i = 0;
        while (visited[i] && i != nums.size())
            ++i;
        
        ans.push_back(i);
        
        return ans;
    }
};
