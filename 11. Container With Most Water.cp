#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


class Solution {
public:
    
    Solution(void) = default;
    
    int maxArea(vector<int>& height)
    {
        int l = 0;
        int r = int(height.size())-1;
        
        int best_area = -1;
        while (l != r)
        {
            int current_area = min(height[l], height[r]) * (r - l);
            
            if (current_area > best_area)
                best_area = current_area;
            
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }
        
        return best_area;
    }
};

int main(void)
{
    vector<int>a{1,2,1};
    
    Solution sol = Solution();
    
    cout << sol.maxArea(a) << endl;
    
    return 0;
}
