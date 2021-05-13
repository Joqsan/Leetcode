#include <iostream>
#include <limits>
#include <cmath>

using namespace std;


// if e is a 9-digit number > than
// the first 9 digits of max, then
// doesnt matter what x is, there
// will be overflow.
// if the first 9 digits of e =
// the first 9 digits of max
// but the last one is greater than 7
// then there'll be overflow
class Solution
{
public:
    Solution(void) = default;
    int reverse(int x)
    {
        int e = 0;
        int flag1 = numeric_limits<int>::max()/10;
        short flag2 = numeric_limits<int>::min()%10;
        while (x != 0)
        {
            e = e * 10 + x % 10;
            x /= 10;
            
            if (abs(e) > flag1 && x != 0)
                return 0;
            if (abs(e) == flag1 && !(x == flag2 || abs(x) < abs(flag2)))
                return 0;
        }
        
        return e;
    }
};


int main(void)
{
    int x = 463847412;
    Solution sol = Solution();
    
    cout << sol.reverse(x) << endl;
    
    cout << x / 10 << endl;
    
    return 0;
    
    
}
