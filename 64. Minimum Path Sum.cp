#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

/*
 
We can reach a given cell in the grid either
 by coming right from above or from the left.
 Then if dp[a][b] is the minimum path sum from
 (0, 0) to (a, b), then clearly:
 
 dp[a][b] = min(dp[a][b-1], dp[a-1][b]) + cost[a][b]
 
 We add a padding from above and from the right with infty
 so that for element in the upper border can be reached only
 from the left and those from the leftmost can be reached
 only from above.
 
 Base cases:
 We also initialize dp[1][0] and dp[0][1] to so that
 dp[1][1] = min(dp[1][0], dp[0][1]) + cost[1][1] = cost[1][1]
 as it should.
 
 Result:
 
 The bottom right has the answer: dp[M][N]
 */

class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int M = grid.size();
        int N = grid[0].size();
        vector<vector<int>> sum(M+1, vector<int>(N+1, INT32_MAX));
        
        sum[1][0] = sum[0][1] = 0;
        for (int a = 1; a != M+1; ++a)
            for (int b = 1; b != N+1; ++b)
                sum[a][b] = min(sum[a-1][b], sum[a][b-1]) + grid[a-1][b-1];
        
        return sum[M][N];
    }
};

int main(void)
{
    string s = "ago";
    string t = "ahbgdc";
    
    Solution sol = Solution();
    
    cout << int(sol.isSubsequence(s, t)) << endl;
    
    return 0;
}
