#include <vector>
#include <iostream>

using namespace std;


/*
 
 Idea:
 
 A node is safe if it's neither in a cycle nor has an
 adjacent node that is in a cycle.
 
 To return all the safe nodes we have to exclude all the
 node satisfying the above condition.
 
 Complexity:
 
 - Time: O(V + E).
 - Space: O(V)
 
 */
enum status {non_visited, in_process, done};

class Solution
{
public:
    bool DFS(const int& u, vector<vector<int>>& graph,vector<status>& visited)
    {
        // if in_proces there u is in a cycle
        // so invalid all the path followed to u.
        // return false
        if (visited[u] == in_process)
            return true;
        
        // If done then it passes for all v in Adj[u]
        // DFS() return false, so its a safe node
        if (visited[u] == done)
            return false;
        
        visited[u] = in_process;
        
        for (auto v : graph[u])
            if (visited[v] == in_process || DFS(v, graph, visited))
                return true;
        
        visited[u] = done;
        
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int N = graph.size();
        vector<int> ans;
        vector<status> visited(N, non_visited);
        
        for (int u = 0; u != N; ++u)
            if (visited[u] == non_visited && !DFS(u, graph, visited))
                ans.push_back(u);
        
        return ans;
    }
};

int main(void)
{
    vector<vector<int>>graph{{0},{2,3,4},{3,4},{0,4},{}};
    
    Solution sol = Solution();
    
    auto res = sol.eventualSafeNodes(graph);
    
    for (auto v : res)
        cout << v << " ";
    cout << endl;
    
    return 0;
}
