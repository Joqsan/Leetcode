#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
            return 1;
        
        int dp = 10;
        
        int base = 9;
        for (int i = 2; i < n+1; ++i)
        {
            base = base * (9 - (i-2));
            dp = base + dp;
        }
        
        return dp;
    }
};

int main(void)
{
    int n = 3;
    Solution sol = Solution();
    
    cout << sol.countNumbersWithUniqueDigits(n) << endl;
    
    return 0;
}
