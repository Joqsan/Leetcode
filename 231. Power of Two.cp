#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        // Case 2^0 = 1;
        if (n == 1)
            return true;
        
        // If n is odd is obviously not a power of two
        if (n % 2)
            return false;
        
        int power = 2;
        
        while (n >= power)
        {
            if (n == power)
                return true;
            
            // position of set bit in power.
            // if power = 2^30 and n != power,
            // then n can't be 2^31, so n in (2^30, 2^31-1]
            // so it's not a power of 2. Return false right
            // away
            if (log2(power) == 30)
                return false;
            
            power <<= 1;
        }
        
        return false;
    }
};

int main(void)
{
    int n = 2147483647;
    
    Solution sol = Solution();
    
    cout << int(sol.isPowerOfTwo(n)) << endl;
    
    return 0;
}
