#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int>& f, int n)
    {
        if (n == 0)
            return true;
        
        if (f[0] == 0 && (f.size() == 1 || f[1] == 0))
        {
            f[0] = 1;
            --n;
        }
        
        int i = 1;
        while (i < f.size()-1 && n)
        {
            if (f[i-1] == 0 && f[i] == 0 && f[i+1] == 0)
                {
                    f[i] = 1;
                    --n;
                }
            ++i;
        }
        
        if (f.size() > 1 && f[i-1] == 0 && f[i] == 0)
        {
            f[i] = 1;
            --n;
        }
        
        
        
        return n == 0;
    }
};

int main(void)
{
    vector<int> nums{1};
    int n = 2;
    Solution sol = Solution();
    
    cout << int(sol.canPlaceFlowers(nums, n)) << endl;
    
    return 0;
}
