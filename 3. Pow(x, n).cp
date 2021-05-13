#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

class Solution
{
public:
    Solution(void) = default;
    
    int i_min = -2147483648;
    int i_max = 2147483647;
    
    double myPow(double x, int n)
    {
        
        double sign = 1.0;
        if (x < 0 && n % 2 == 1)
        {
            sign = -1.0;
            x = abs(x);
        }
        
        if (n == 0 || abs(x) == 1.0)
            return sign*1.0;
        
        if (n == i_min && x > 1.0)
            return 0.0;
        else if (n == i_max && x < 1.0)
            return 0.0;
        
        x = (n > 0) ? x : 1/x;
        n = abs(n);
        
        unsigned int k = 2;
        
        double base = x;
        while (k <= n)
        {
            x *= x;
            k = k << 1;
        }
        
        if (k > n)
        {
            k = k >> 1;
            for (int i = k+1; i <= n; ++i)
                x *= base;
        }
        
        return sign * x;
    }
};


int main(void)
{
    double x = -2;
    int n = 3;
    
    Solution sol = Solution();
    
    cout << sol.myPow(x, n) << endl;
    
//    cout << numeric_limits<int>::max() << endl;
    return 0;
    
}

