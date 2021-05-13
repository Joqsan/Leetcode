#include <vector>
#include <iostream>

using namespace std;



class Solution
{
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix)
    {
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        vector<int> col_max(col_size, INT32_MIN);
        vector<int> row_min(row_size, INT32_MAX);
        vector<int> ans;
        
        for (int r = 0; r != row_size; ++r)
            for (int c = 0; c != col_size; ++c)
            {
                col_max[c] = max(col_max[c], matrix[r][c]);
                row_min[r] = min(row_min[r], matrix[r][c]);
            }
        
        for (int r = 0; r < row_size; ++r)
            for (int c = 0; c < col_size; ++c)
                if (row_min[r] == col_max[c])
                    ans.push_back(row_min[r]);
        
        return ans;
            
    }
};

int main(void)
{
    vector<vector<int>> matrix{{3,7,8},{9,11,13},{15,16,17}};
    
    Solution sol = Solution();
    
    auto res = sol.luckyNumbers(matrix);
    
    for (auto v : res)
        cout << v << " ";
    cout << endl;
    
    return 0;
}
