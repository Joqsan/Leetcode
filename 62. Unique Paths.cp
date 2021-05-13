#include <vector>
#include <iostream>

using namespace std;



/*
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
 
 ==========================
 
 The problem has also a combinatorial solution.
 - A path from (0, 0) to (m-1, n-1) will have
 n-1 + m-1 = n+m-2 cells.
 - A cell (r, c) can be denoted by D if we reach it
 by going Down from (r-1,c), or R if it was reached
 by doing a step to the right from (r, c-1).
 - We'll go down m-1 times.
 - We'll go right n-1 time.
 - Therefore the problem to finding the number of way
 of arraging m-1 D letters with n-1 R letters. This is
 just permutations with repetitions.
 
 Answer: P(m-1, n-1) = (m+n-2)! / [(m-1)! * (n-1)!]
 */

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        // we can initialize the dp matrix to ones from
        // the get go in order to avoid doing the loop
        // below.
//        for (int c = 0; c != n; ++c)
//            dp[0][c] = 1;
        
        for (int r = 1; r != m; ++r)
            for (int c = 0; c != n; ++c)
            {
                int other = (c-1 >= 0) ? dp[r][c-1] : 0;
                dp[r][c] = dp[r-1][c] + other;
            }
        
        
        return dp[m-1][n-1];
    }
};

int main(void)
{
    int m = 3;
    int n = 7;
    
    Solution sol = Solution();
    
    cout << sol.uniquePaths(m, n) << endl;
    
    return 0;
}
