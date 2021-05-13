#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int diagonalSum(vector<vector<int>>& mat)
    {
        int total_sum = 0;
        int N = mat.size();
        
        for (int i = 0; i != N; ++i)
            total_sum += mat[i][i] + mat[i][N-1-i];
        
        if (N % 2)
            total_sum -= mat[N/2][N/2];
        
        return total_sum;
    }
};

int main(void)
{
    vector<vector<int>> mat{{7,3,1,9},{3,4,6,9},{6,9,6,6},{9,5,8,5}};
    Solution sol = Solution();
    
    cout << sol.diagonalSum(mat) << endl;
    
    return 0;
}
