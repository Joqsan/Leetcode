#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix)
    {
        int R = matrix.size();
        int C = matrix[0].size();
        
        vector<vector<int>> ans(C, vector<int>(R));
        
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                ans[j][i] = matrix[i][j];
        
        return ans;
    }
};
