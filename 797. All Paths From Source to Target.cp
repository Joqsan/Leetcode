#include <vector>
#include <stack>
#include <iostream>

using namespace std;


/*
 1) The graph is guaranteed to be DAG, so if we are visiting vertex u, we're
 guaranteed to never visit one of its ancestors. That is, there is no need
 to check for vertices already visited (we'll always be looking forward).
 
 Algorithm: We go forward from 0. Each time a new vertex is visited we
 add it to path. If the last discovered vertex is the target, we save the
 whole path.
 
 If we already explored all possible paths from vertex u, then this vertex
 will no longer be in a path from 0 to target, so we remove it from the
 current path (path.pop_back()).
 
 This guarantees that when u == target, path has a valid path from 0 to target.
 And from 1) and DFS it follows that that path is a new one.
 
 
 Complexity:
 
 - Time : O(E + V)
 - Space: O(V^3) (not tight)
 */
class Solution
{
public:
    vector<vector<int>> ans;
    int target;
    
    void DFS(const int& u, vector<vector<int>>& graph, vector<int>& path)
    {
        path.push_back(u);
        
        if (u == target)
            ans.push_back(path);
        
        for (auto v : graph[u])
            DFS(v, graph, path);
        
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        vector<int> path;
        target = graph.size()-1;
        
        DFS(0, graph, path);
        
        return ans;
    }
};

int main(void)
{
    vector<vector<int>> graph{{4,3,1},{3,2,4},{3},{4},{}};
    
    Solution sol = Solution();
    
    auto res = sol.allPathsSourceTarget(graph);
    
    for (auto path : res)
    {
        for (auto v : path)
            cout << v << " ";
        cout << endl;
    }
    
    return 0;
}
