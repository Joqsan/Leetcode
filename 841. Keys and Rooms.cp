#include <vector>
#include <stack>
#include <iostream>

using namespace std;


/*
 Asking whether we can enter all rooms starting from zero
 is the same as asking whether we can reach every room
 starting from zero.
 
 Do a DFS from 0 and count all the rooms that are reachable from
 it, if all the rooms reachables from 0 is not equal to the total
 number of rooms, then return false. Return true otherwise.
 
 */

class Solution
{
public:
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        vector<bool> visited(rooms.size(), false);
        stack<int> Q;
        int unreachables = rooms.size();
        Q.push(0);
        
        while (!Q.empty())
        {
            auto u = Q.top();
            Q.pop();
            
            if (visited[u])
                continue;
            
            visited[u] = true;
            --unreachables;
            
            for (auto v : rooms[u])
                if (!visited[v])
                    Q.push(v);
        }
        
        return (unreachables == 0);
    }
};

int main(void)
{
    vector<vector<int>> rooms{{1},{2},{3},{}};
    
    Solution sol = Solution();
    
    cout << int(sol.canVisitAllRooms(rooms)) << endl;
    
    return 0;
}
