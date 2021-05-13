#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    Solution(void) = default;
        int trap(vector<int>& height)
        {
            vector<int> temp(height.size(), 0);
            int n = height.size();
            int k = 0;
            
            if (n ==  0)
                return 0;
            
            int water = 0;
            
            for (int i = 0; i != n-1; ++i)
            {
                if (height[k] >= height[i])
                    temp[i] = height[k] - height[i];
                else
                    k = i;
                
            }
            
            k = n-1;
            for (int i = n-1; i != 0; --i)
            {
                if (height[i] <= height[k])
                    water += min(temp[i], height[k] - height[i]);
                else
                    k = i;
                
            }
            
            return water;
        }
};

int main(void)
{
    vector<int> a{4,2,0,3,2,5};
    
    Solution sol = Solution();
    
    cout << sol.trap(a) << endl;
    
    return 0;
    
}

// 0,1,0,2,1,0,1,3,2,1,2,1
// 0,0,1,1,2,4,5,5,6,8,1,
