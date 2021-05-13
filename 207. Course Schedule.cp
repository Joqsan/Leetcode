#include <vector>
#include <iostream>

using namespace std;


enum process{nonVisited, inProcess, done};

class Solution
{
private:
    vector<vector<int>> Adj;
    void DFSVisit(const int &u, vector<process> &vertexStatus, bool &canWe);
public:
    
    Solution(void) = default;
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        
        Adj.resize(numCourses);
        int n = prerequisites.size();
        vector<process> vertexStatus(numCourses, nonVisited);
        
        // Create graph
        for (int e = 0; e != n; ++e)
        {
            int u = prerequisites[e][0];
            int v = prerequisites[e][1];
            
            Adj[u].push_back(v);
        }
        
        bool canWe = true;
        for (int u = 0; u != numCourses && canWe; ++u)
            if (vertexStatus[u] == nonVisited)
                DFSVisit(u, vertexStatus, canWe);
        
        return canWe;
    }
};


void Solution::DFSVisit(const int &u, vector<process> &vertexStatus, bool &canWe)
{
    vertexStatus[u] = inProcess;
    
    for (auto v : Adj[u])
    {
        if (vertexStatus[v] == nonVisited)
            DFSVisit(v, vertexStatus, canWe);
        else if (vertexStatus[v] == inProcess)
        {
            canWe = false;
            break;
        }
    }
    
    vertexStatus[u] = done;
}

int main(void)
{
    vector<vector<int>> a{{0,0}};
    int numCourses = 1;
    
    Solution sol = Solution();
    
    cout << sol.canFinish(numCourses, a) << endl;
    
    return 0;
}
