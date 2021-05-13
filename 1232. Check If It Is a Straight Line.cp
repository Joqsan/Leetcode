#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates)
    {
        int dy = coordinates[1][1] - coordinates[0][1];
        int dx = coordinates[1][0] - coordinates[0][0];
        
        for (int i = 2; i != coordinates.size(); ++i)
        {
            auto p = coordinates[i]; // the i-th point
            
            if (dy * (p[0] - coordinates[0][0]) != dx * (p[1] - coordinates[0][1]))
                return false;
        }
        
        return true;
    }
};


int main(void)
{
    vector<vector<int>> coor{{-4,-3},{1,0},{3,-1},{0,-1},{-5,2}};
    
    Solution sol = Solution();
    
    cout << sol.checkStraightLine(coor) << endl;
    
    return 0;
}
