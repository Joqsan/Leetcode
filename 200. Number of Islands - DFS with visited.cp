#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class Solution
{
public:
    int n_rows;
    int n_cols;
    void DFS_Visit(const int& u1, const int& u2, vector<vector<bool>> &visited, vector<vector<char>>& grid)
    {
        visited[u1][u2] = true;
        
        for (auto move : {-1, 1})
        {
            if (u1 + move >= 0 && u1 + move < n_rows)
                if (grid[u1+move][u2] == '1' && !visited[u1+move][u2])
                    DFS_Visit(u1+move, u2, visited, grid);
            
            if (u2 + move  >= 0 && u2 + move < n_cols)
                if (grid[u1][u2+move] == '1' && !visited[u1][u2+move])
                    DFS_Visit(u1, u2+move, visited, grid);
        }
        
        
    }
    
    int numIslands(vector<vector<char>>& grid)
    {
        n_rows = grid.size();
        n_cols = grid[0].size();
        int n_islands = 0;
        
        vector<vector<bool>> visited(n_rows, vector<bool>(n_cols, false));
        
        for (int i = 0; i != n_rows; ++i)
            for (int j = 0; j != n_cols; ++j)
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    DFS_Visit(i, j, visited, grid);
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
