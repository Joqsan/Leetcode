#include <vector>
#include <iostream>

using namespace std;

/*
 
 This is from 62. Unique Paths:
 
 Let dp[r][c] be de number of ways of reaching
 cell (r, c).
 The dp[r][c] = dp[r-1][c] + dp[r][c-1], where
 - dp[r-1][c] when we reach (r,c) from above
 - dp[r][c-1] when we reach (r,c) from the left.
 
 
 Base case:
 dp[0][c] = 1, because there is only one way
 we can reach a cell in the first row (row r=0): from the left.
 dp[0][0] = 1, which mean we stand still in (0,0).
 
 Result:
 Answer in dp[m-1][n-1]
 
 The only think we have to care about is that if (r, c) is a cell
 with an obstacle (obstacleGrid[r][c] == 1), then we have to skip it.
 In that way dp[r][c] = 0 and every path coming from the obstacle is
 zero (as it should).
 
 */

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        if (obstacleGrid[0][0] == 0)
            dp[0][0] = 1;
        
        for (int r = 0; r != m; ++r)
            for (int c = 0; c != n; ++c)
            {
                if (obstacleGrid[r][c] == 0)
                {
                    if (r-1 >= 0)
                        dp[r][c] += dp[r-1][c];
                    
                    if (c-1 >= 0)
                        dp[r][c] += dp[r][c-1];
                }
            }
        
        
        return dp[m-1][n-1];
        
    }
};

int main(void)
{
    vector<vector<int>> nums{{0}};
    
    Solution sol = Solution();
    
    cout << sol.uniquePathsWithObstacles(nums) << endl;
    
    return 0;
}


