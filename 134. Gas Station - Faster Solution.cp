#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

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
            total += gas[i] - cost[i];
            
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
