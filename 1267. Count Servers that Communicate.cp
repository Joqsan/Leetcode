#include <vector>
#include <stack>

using namespace std;

/*
 
 - Find the number of server in each row and columns.
 - If in the a cell there is a server and the row or
    col count is > 1, then the server is connected.
 
 Complexity:
 - Time: O(m*n).
 - Space: O(m+n).
 
 */

class Solution
{
public:
    
    int countServers(vector<vector<int>>& grid)
    {
        int R = (int)grid.size();
        int C = (int)grid[0].size();
        
        vector<int> row_count(R, 0);
        vector<int> col_count(C, 0);
        
        for (int r = 0; r != R; ++r)
            for (int c = 0; c != C; ++c)
                if (grid[r][c])
                {
                    ++row_count[r];
                    ++col_count[c];
                }
        
        int ans = 0;
        for (int r = 0; r != R; ++r)
            for (int c = 0; c != C; ++c)
                if (grid[r][c] && (row_count[r] > 1 || col_count[c] > 1))
                    ++ans;
        
        return ans;
    }
};
