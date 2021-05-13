#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

/*
 
 Definition:
 dp[d][t] - number of ways of adding up to t using d dice
 
 Recurrence:
 dp[d][t] = sum_{i \in faces} dp[d-1][t - i]
 
 Explanation:
 - Let say we fixed the d-th die with the i-th side facing up.
 - Then the problem is reduced to the subproblem of dp[d-1][t - i].
 
 Approach:
 Bottom Up: from a target of 1 to a target of target xD
 
 Result:
 dp[d][t].
 
 */

class Solution
{
public:
    int numRollsToTarget(int d, int f, int target)
    {
        vector<vector<int>> dp(d+1, vector<int>(target+1, 0));
        int mod = pow(10, 9) + 7;
        dp[0][0] = 1;
        
        for (int curr_target = 1; curr_target <= target; ++curr_target)
            for (int n_die = 1; n_die <= d; ++n_die)
                for (int curr_face = 1; curr_face <= f; ++curr_face)
                    if (curr_target - curr_face >= 0)
                    {
                        dp[n_die][curr_target] += dp[n_die-1][curr_target-curr_face];
                        dp[n_die][curr_target] %= mod;
                    }
        
        return dp[d][target];
    }
};

int main(void)
{
    int d = 30;
    int f = 30;
    int target = 500;
    
    Solution sol = Solution();
    
    cout << sol.numRollsToTarget(d, f, target) << endl;
    
    return 0;
}
