#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>
#include <iostream>

using namespace std;

/*
 
 Aproach:
 - Use priority queue to sort the numbers (keepin track of their indices).
 - i - keeps track of the real count of number less than the current one.
 - j - keeps track of the number of elements already popped from the queue.
 
 Complexity:
 - Time: O(n*logn) (assuming that the priority queue in implemented as a heap
 - Space: O(2*n + 2*n)
 */

typedef pair<int, int> n_to_id;
class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums)
    {
        priority_queue<n_to_id, vector<n_to_id>, greater<n_to_id>> Q;
        unordered_map<int, bool> visited;
        
        int i = 0;
        for (; i != nums.size(); ++i)
            Q.push({nums[i], i});
        
        i = 0;
        int j = 0;
        while (!Q.empty())
        {
            auto [u, id] = Q.top();
            Q.pop();
            
            if (visited[u])
                --i;
            else
            {
                visited[u] = true;
                i = j;
            }
            
            nums[id] = i++;
            j++;
        }
        
        return nums;
    }
};

int main(void)
{
    vector<int> nums{7,7,7,8};
    Solution sol = Solution();
    
    auto res = sol.smallerNumbersThanCurrent(nums);
    
    for (auto v : res)
        cout << v << " ";
    cout << endl;
    
    return 0;
}
