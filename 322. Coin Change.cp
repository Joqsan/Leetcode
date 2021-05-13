#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int infty = numeric_limits<short>::max();

class Solution
{
public:
    
    Solution(void) = default;
    
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int>sum(amount+1, infty);
        
        sum[0] = 0;
        
        for (int x = 1; x != amount+1; ++x)
            for (auto c : coins)
                if (x - c >= 0)
                    sum[x] = min(sum[x], sum[x-c] + 1);
                    
        
        return (sum[amount] != infty) ? sum[amount] : -1;
    }
};

int main(void)
{
    vector<int> coins{5, 7, 9};
    int amount = 6;
    
    Solution sol = Solution();
    
    cout << sol.coinChange(coins, amount) << endl;
    
    return 0;
}
