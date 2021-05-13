#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;


class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int N = nums.size();
        vector<bool> visited(N, false);
        vector<int> d(N);
        queue<int> Q;
        
        d[0] = 0;
        visited[0] = true;
        Q.push(0);
        
        while (!Q.empty())
        {
            auto u = Q.front();
            Q.pop();
            
            int max_shift = nums[u];
            
            for (int v = u+1; v <= u+max_shift && v < N; ++v)
                if (!visited[v])
                {
                    visited[v] = true;
                    d[v] = d[u] + 1;
                    Q.push(v);
                }
        }
        
        return d[N-1];
    }
};

int main(void)
{
    vector<int> nums{10,9,8,7,6,5,4,3,2,1,1,0};
    Solution sol = Solution();
    
    cout << sol.jump(nums) << endl;
    
    return 0;
}
