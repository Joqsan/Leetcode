#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 
 Complexity:
 - Time: O(N^2)
 - Space: O(N^2)
 
 Going from bottom to the top is less troubling
 
 */
class Solution
{
public:
    int minimumTotal(vector<vector<int>>& tr)
    {
        int R = tr.size();
        int min_sum;
        
        if (tr.size() == 1)
            return tr[0][0];
        
        for (int r = R-2; r >= 0; --r)
        {
            int min_row = INT32_MAX;
            int row_size = tr[r].size();
            
            for (int i = 0; i != row_size; ++i)
            {
                tr[r][i] = tr[r][i] + min(tr[r+1][i], tr[r+1][i+1]);
                
                min_row = min(min_row, tr[r][i]);
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
