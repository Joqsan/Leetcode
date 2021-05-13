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
        
        vector<int> dp(n+1, 0);
        
        dp[1] = 10;
        
        int base = 9;
        int k = 9;
        for (int i = 2; i < n+1; ++i)
        {
            dp[i] = base * k + dp[i-1];
            base = base * k;
            --k;
        }
        
        return dp[n];
    }
};

int main(void)
{
    int n = 3;
    Solution sol = Solution();
    
    cout << sol.countNumbersWithUniqueDigits(n) << endl;
    
    return 0;
}
