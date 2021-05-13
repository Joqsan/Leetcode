#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n+1);
        
        dp[0] = 1;
        dp[1] = 1;
        
        for (int k = 2; k != n+1; ++k)
            dp[k] = dp[k-1] + dp[k-2];
        
        return dp[n];
    }
};

int main(void)
{
    int n = 3;
    
    Solution sol = Solution();
    
    cout << sol.climbStairs(n) << endl;
    
    return 0;
}
