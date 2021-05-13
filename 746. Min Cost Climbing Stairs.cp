#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 dp[n] - minimum cost climbing to top of a n-step staircase.
 dp[n] = min(dp[n-1], dp[n-2]) + cost[n]
 - This reads: min(dp[n-1], dp[n-2]) + cost[n] =
 = min(dp[n-1] + cost[n], dp[n-2] + cost[n]). That is, we
 select the minimum cost of reaching the n-th step between climbing
 from one step below (the (n-1)-th one) of climbing from
 two steps below.
 
 Base cases:
 From the start we can reach immediately the first and second steps. So:
 dp[0] = cost[0]
 dp[1] = cost[1]
 
 Answer:
 We reach the top of the floor at step N by climbing from the (N-1)-th
 or (N-2)-th step. We find the minimum between them and we're done.
 */


class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int N = cost.size();
        vector<int> dp(N);
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int n = 2; n != N; ++n)
            dp[n] = min(dp[n-1], dp[n-2]) + cost[n];
        
        return min(dp[N-1], dp[N-2]);
    }
};


int main(void)
{
    vector<int> cost{10, 15, 20};
    
    Solution sol = Solution();
    
    cout << sol.minCostClimbingStairs(cost) << endl;
    
    return 0;
}
