#include <limits>
#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        
        int e = 0;
        int y = x;
        
        while (y != 0)
        {
            e = e * 10 + y % 10;
            y /= 10;
            
            if (e > INT32_MAX/10 && y != 0)
                return false;
        }
        
        return e == x;
        
    }
};

int main(void)
{
    Solution sol = Solution();
    int x = 1000000001;
    
    cout << sol.isPalindrome(x) << endl;
    
    return 0;
}
