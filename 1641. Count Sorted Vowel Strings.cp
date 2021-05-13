#include <iostream>
#include <vector>

using namespace std;

enum vowels{a, e, i, o, u};
class Solution
{
public:
    
    Solution(void) = default;
    
    int countVowelStrings(int n)
    {
        vector<vector<int>> dp(n+1, vector<int>(5));
        
        // dp[l][a] : the number l-length string
        // ending in an a.
        for (int v = a; v != u+1; ++v)
            dp[1][v] = 1;
        
        // the l-length string ending in vowel i
        // is ordered if the i was added to an ordered
        // (l-1)-length string ending in a, e, or i.
        for (int l = 2; l != n+1; ++l)
        {
            dp[l][a] = dp[l-1][a];
            dp[l][e] = dp[l-1][a] + dp[l-1][e];
            dp[l][i] = dp[l-1][a] + dp[l-1][e] + dp[l-1][i];
            dp[l][o] = dp[l-1][a] + dp[l-1][e] + dp[l-1][i] + dp[l-1][o];
            dp[l][u] = dp[l-1][a] + dp[l-1][e] + dp[l-1][i] + dp[l-1][o] + dp[l-1][u];
        }
        
        return dp[n][a] + dp[n][e] + dp[n][i] + dp[n][o] + dp[n][u];
    }
};

int main(void)
{
    int n = 33;
    
    Solution sol = Solution();
    
    cout << sol.countVowelStrings(n) << endl;
    
    return 0;
}
