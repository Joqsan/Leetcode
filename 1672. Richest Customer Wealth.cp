#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximumWealth(vector<vector<int>>& accounts)
    {
        int global_max = INT32_MIN;
        int R = accounts.size();
        int C = accounts[0].size();
        
        for (int r = 0; r != R; ++r)
        {
            int local_sum = 0;
            for (int c = 0; c != C; ++c)
                local_sum += accounts[r][c];
            
            global_max = max(global_max, local_sum);
        }
        
        return global_max;
    }
};
