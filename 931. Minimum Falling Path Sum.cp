#include <vector>
#include <iostream>

using namespace std;


/*
 Let dp[r][c] the path of minimum sum to
 reach cell (r, c).
 The evidently dp[r][c] = min(dp[r-1][c-1], dp[r-1][c], dp[r-1][c+1]) + matrix[r][c]
 
 Base Case:
 dp[0][c] = matrix[0][c] for every c.
 
 Result:
 The goal is to reach the bottom row.
 The minimum sum path is correspond to min_{c in [0, N-1]}(dp[M-1][c])
 
 */
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int M = matrix.size();
        int N = matrix[0].size();
        
        vector<vector<int>> dp(M, vector<int>(N+2, INT32_MAX));
        
        for (int c = 1; c != N+1; ++c)
            dp[0][c] = matrix[0][c-1];
        
//        dp[0][0] = dp[0][N+1] = 0;
        
        int min_sum = INT32_MAX;
        
        for (int r = 1; r != M; ++r)
            for (int c = 1; c != N+1; ++c)
            {
                dp[r][c] = min(min(dp[r-1][c-1], dp[r-1][c]), dp[r-1][c+1]) + matrix[r][c-1];
                
                if (r == M-1)
                    min_sum = min(min_sum, dp[r][c]);
            }
        
        return min_sum;
    }
};

int main(void)
{
    vector<vector<int>> nums{{2,1,3},{6,5,4},{7,8,9}};
    
    Solution sol = Solution();
    
    cout << sol.minFallingPathSum(nums) << endl;
    
    return 0;
}
