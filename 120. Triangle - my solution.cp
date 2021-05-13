#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 
 Complexity:
 - Time: O(N^2)
 - Space: O(N^2)
 
 */
class Solution
{
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int R = triangle.size();
        vector<vector<int>> dp;
        int min_sum = triangle[0][0];
        
        dp.push_back({triangle[0][0]});
        for (int r = 1; r != R; ++r)
        {
            int min_row = INT32_MAX;
            int row_size = triangle[r].size();
            
            dp.push_back(vector<int>(row_size, INT32_MAX));
            for (int i = 0; i != row_size; ++i)
            {
                if (i-1 >= 0)
                {
                    int left = dp[r-1][i-1] + triangle[r][i];
                    dp[r][i] = min(dp[r][i], left);
                }
                
                if (i < row_size - 1)
                {
                    int above = dp[r-1][i] + triangle[r][i];
                    dp[r][i] = min(dp[r][i], above);
                }
                
                min_row = min(min_row, dp[r][i]);
            }
            
            min_sum = min_row;
        }
        
        return min_sum;
    }
};

int main(void)
{
    vector<vector<int>>tria{{2},{3,4},{6,5,9},{4,4,8,0}};
    
    Solution sol = Solution();
    
    int a = 0;
    
    cout << (a << 1) << endl;
    cout << (a << 1) + 1 << endl;
    cout << sol.minimumTotal(tria) << endl;
    
    return 0;

}
