#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

/*
 
 The solution is based on two facts:
 
 1) Let B be the first node not reachable from A.
 Then any node between A and B cannot reach B either.
 Proof: Suppose there exist a node C between A and B
 such that B can be reached from (C -> B). Since B is the first
 non-reachable node from A, then A can reach any node before
 B, including C. So A -> C and C -> B ==> A -> B. A contradiction.
 
 2) If the total number of gast is not less than the total cost, then
 there is a solution.
 Proof: this follows from the fact that all gas stations and costs have
 to be included in the path, disregarding the starting point.
 
 3) If there is a solution, then this solution is unique.
 Proof: This is a given condition.
 
 Question: If there is a path and n-i -> 0, what guarantees
 that 0 -> n-i?
 Answer: Suppose n-i -> 0, but 0 -/-> n-i. Then by property 1)
 with A = n-i and B = n-i, every node between A and B
 (between n-i and n-i) cannot reach B = n-i. So n-(i+1) -/-> n-i,
 ..., n -/-> n-i, 0 -/-> n-i. This contradicts the fact that
 there is a path.
 
 */

class Solution
{
public:
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int total = 0;
        int tank = 0;
        int start = 0;
        
        for (int i = 0; i != gas.size(); ++i)
        {
            tank += gas[i] - cost[i];
            total += gas[i] - cost[i]; // This is for checking property 2)
            
            // Here we apply property 1)
            if (tank < 0)
            {
                tank = 0;
                start = i+1;
            }
        }
        
        return (total < 0) ? -1 : start;
    }
};

int main(void)
{
    vector<int> gas{2,3,4};
    vector<int> cost{3,4,3};
    
    Solution sol = Solution();
    
    cout << sol.canCompleteCircuit(gas, cost) << endl;
    
    return 0;
}
