#include <vector>
#include <iostream>

using namespace std;

class Solution
{
    
public:
    
    void DFS_Visit(const int &u, vector<bool> &visited, vector<vector<int>> &Adj)
    {
        visited[u] = true;
        
        for (auto v : Adj[u])
            if (!visited[v])
                DFS_Visit(v, visited, Adj);
    }
    
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        if (connections.size() < n-1)
            return -1;
        
        int n_components = 0;
        vector<vector<int>> Adj(n);
        vector<bool> visited(n, false);
        
        for (auto e : connections)
        {
            Adj[e[0]].push_back(e[1]);
            Adj[e[1]].push_back(e[0]);
        }
        
        for (int u = 0; u != n; ++u)
            if (!visited[u])
            {
                ++n_components;
                DFS_Visit(u, visited, Adj);
            }
        
        return n_components-1;
    }
};

int main(void)
{
    int n = 4;
    vector<vector<int>> conn{{0,1},{0,2},{1,2}};
    
    Solution sol = Solution();
    
    cout << sol.makeConnected(n, conn) << endl;
    
    return 0;
}
