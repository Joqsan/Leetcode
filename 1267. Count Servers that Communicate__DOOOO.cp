#include <vector>
#include <utility>
#include <stack>
#include <iostream>

using namespace std;

typedef pair<int, int> cell;

// try queue on row and col separately
class Solution
{
public:
    int R, C;
    vector<bool> row_vis;
    vector<bool> col_vis;
    
    int traverse(int r, int c, vector<vector<int>>& grid)
    {
        stack<cell> Q;
        
        Q.push({r, c});
        grid[r][c] = -1;
        
        int counter = 0;
        while (!Q.empty())
        {
            auto [x, y] = Q.top();
            Q.pop();
            
            ++counter;
            
            int fwd = 1;
            int bwd = -1;
            
            while (r + fwd < R)
            {
                if (grid[r+fwd][c] == 1)
                {
                    grid[r+fwd][c] = -1;
                    Q.push({r+fwd, c});
                }
                else if (grid[r+fwd][c] == -1)
                    break;
                
                ++fwd;
            }
            
            while (r + bwd >= 0)
            {
                if (grid[r+bwd][c] == 1)
                {
                    grid[r+bwd][c] = -1;
                    Q.push({r+bwd, c});
                }
                else if (grid[r+bwd][c] == -1)
                    break;
                
                --bwd;
            }
            
            fwd = 1;
            bwd = -1;
            
            while (c + fwd < C)
            {
                if (grid[r][c+fwd] == 1)
                {
                    grid[r][c+fwd] = -1;
                    Q.push({r, c+fwd});
                }
                else if (grid[r][c+fwd] == -1)
                    break;
                
                ++fwd;
            }
            
            
            while (c + bwd >= 0)
            {
                if (grid[r][c+bwd] == 1)
                {
                    grid[r][c+bwd] = -1;
                    Q.push({r, c+bwd});
                }
                else if (grid[r][c+bwd] == -1)
                    break;
                
                --bwd;
            }
        }
        
        return (counter == 1) ? 0 : counter;
    }
    
    int countServers(vector<vector<int>>& grid)
    {
        R = (int)grid.size();
        C = (int)grid[0].size();
        
        int total = 0;
        
        for (int r = 0; r != R; ++r)
            for (int c = 0; c != C; ++c)
            {
                if (grid[r][c] == 0)
                    grid[r][c] = -1;
                else if (grid[r][c] == 1)
                    total += traverse(r, c, grid);
            }
        
        return total;
    }
};

int main(void)
{
    vector<vector<int>> grid{{1,0}, {1, 1}};
    
    Solution sol = Solution();
    
    cout << sol.countServers(grid) << endl;
    
    return 0;
    
}
