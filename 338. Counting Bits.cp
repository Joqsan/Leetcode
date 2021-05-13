#include <vector>
#include <iostream>

using namespace std;

/*
 Examples:
 
   1    &   ~(1 << 0) = 0
  10    &   ~(1 << 1) = 0
  11    &   ~(1 << 1) = 1
 100    &   ~(1 << 2) = 0
 101    &   ~(1 << 2) = 01
 110    &   ~(1 << 2) = 10
 111    &   ~(1 << 2) = 11
 1000   &   ~(1 << 4) = 0
 In general: n & ~(1 << k) will
 set the last one of n to zero
 (if k gives the correspoding shift)
 
 Therefore:
 
 dp[100] = dp[00] + 1;
 dp[101] = dp[01] + 1;
 dp[110] = dp[10] + 1;
 dp[111] = dp[11] + 1;
 etc
 
 Base case:
 dp[0] = 0;
 */
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> dp(num+1);
        
        int k = 0;
        dp[0] = 0;
        for (int n = 1; n <= num; ++n)
        {
            
            dp[n] = dp[n & ~(1 << k)] + 1;
            
            if ((n+1) % (1 << (k+1)))
                ++k;
        }
        
        return dp;
    }
};

int main(void)
{
    int num = 3;
    Solution  sol = Solution();
    
    auto re = sol.countBits(num);
    
    for (auto v : re)
        cout << v << " ";
    cout << endl;
    
    return 0;
}
