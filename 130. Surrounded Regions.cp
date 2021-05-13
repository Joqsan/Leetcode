#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int R, C;
    void DFS(const int &r, const int &c, vector<vector<char>>& board)
    {
        board[r][c] = '1';
        
        for (auto shift : {-1, 1})
        {
            if (r + shift >= 0 && r + shift < R)
                if (board[r+shift][c] == 'O')
                    DFS(r+shift, c, board);
            
            if (c + shift >= 0 && c + shift < C)
                if (board[r][c+shift] == 'O')
                    DFS(r, c+shift, board);
        }
    }
    
    void solve(vector<vector<char>>& board)
    {
        R = board.size();
        C = board[0].size();
        
        for (int c = 0; c != C; ++c)
        {
            if (board[0][c] == 'O')
                DFS(0, c, board);
            
            if (board[R-1][c] == 'O')
                DFS(R-1, c, board);
        }
        
        for (int r = 0; r != R; ++r)
        {
            if (board[r][0] == 'O')
                DFS(r, 0, board);
            
            if (board[r][C-1] == 'O')
                DFS(r, C-1, board);
        }
        
        for (int r = 1; r < R-1; ++r)
            for (int c = 1; c < C-1; ++c)
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
        
        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c)
                if (board[r][c] == '1')
                    board[r][c] = 'O';
                
    }
};

int main(void)
{
    vector<vector<char>> board{{'X'}};
    
    Solution sol = Solution();
    
    sol.solve(board);
    
    for (auto row : board)
    {
        for (auto v : row)
            cout << v << " ";
        cout << endl;
    }
    
    return 0;
}
