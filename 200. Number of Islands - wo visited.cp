#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class Solution
{
public:
    int n_rows;
    int n_cols;
    void DFS_Visit(const int& u1, const int& u2, vector<vector<char>>& grid)
    {
        grid[u1][u2] = '0';
        
        for (auto move : {-1, 1})
        {
            if (u1 + move >= 0 && u1 + move < n_rows)
                if (grid[u1+move][u2] == '1')
                    DFS_Visit(u1+move, u2, grid);
            
            if (u2 + move  >= 0 && u2 + move < n_cols)
                if (grid[u1][u2+move] == '1')
                    DFS_Visit(u1, u2+move, grid);
        }
        
        
    }
    
    int numIslands(vector<vector<char>>& grid)
    {
        n_rows = grid.size();
        n_cols = grid[0].size();
        int n_islands = 0;
        
        for (int i = 0; i != n_rows; ++i)
            for (int j = 0; j != n_cols; ++j)
                if (grid[i][j] == '1')
                {
                    DFS_Visit(i, j, grid);
                    ++n_islands;
                }
        
        return n_islands;
    }
};

int main(void)
{
    vector<vector<char>> grid{{'1','1','1'},{'0','1','0'},{'1','1','1'}};
    
    Solution sol = Solution();
    
    cout << sol.numIslands(grid) << endl;
    
    return 0;
}
