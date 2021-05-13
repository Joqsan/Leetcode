#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;


/*
 The subordination relatioship is guaranteed to form a tree.
 Let's explore every possible path from the head.
 
 The answer is the path from head to bottom having the largest
 sum.
 
 Complexity:
 
 - Time: O(n).
 - Space: O(h).
 */
class Solution
{
public:
    int total_sum = INT32_MIN;
    vector<vector<int>> Adj;
    
    void DFS(const int& u, vector<int>& manager, vector<int>& informTime, int curr_sum)
    {
        if (informTime[u] == 0)
        {
            total_sum = max(total_sum, curr_sum);
            return;
        }
        
        for (auto v : Adj[u])
            DFS(v, manager, informTime, curr_sum + informTime[manager[v]]);
    
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        Adj.resize(n);
        
        for (int v = 0; v != n; ++v)
            if (manager[v] != -1)
                Adj[manager[v]].push_back(v);
        
        DFS(headID, manager, informTime, 0);
        
        return total_sum;
    }
};

int main(void)
{
    int n = 11;
    int headID = 4;
    vector<int> manager{5,9,6,10,-1,8,9,1,9,3,4};
    vector<int> informTime{0,213,0,253,686,170,975,0,261,309,337};
    
    Solution sol = Solution();
    
    cout << sol.numOfMinutes(n, headID, manager, informTime) << endl;
    
    return 0;
}
