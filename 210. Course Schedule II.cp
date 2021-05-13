#include <vector>
#include <iostream>
#include <deque>
using namespace std;

enum process{non_visited, in_process, done};

class Solution
{
private:
    vector<vector<int>> Adj;
//    vector<vector<int>> Adj_T;
    deque<int> sorted_vertices;
public:
    Solution(void) = default;
    
    void DFS_Visit(const int &u, vector<process> &vertex_status, bool &no_cycle)
    {
        vertex_status[u] = in_process;
        
        for (auto v : Adj[u])
        {
            if (vertex_status[v] == non_visited)
                DFS_Visit(v, vertex_status, no_cycle);
            else if (vertex_status[v] == in_process)
            {
                no_cycle = false;
                break;
            }
        }
        
        vertex_status[u] = done;
        sorted_vertices.push_front(u);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        int n = prerequisites.size();
        
        Adj.resize(numCourses);
        vector<process> vertex_status(numCourses, non_visited);
        
        for (int e = 0; e != n; ++e)
        {
            int u = prerequisites[e][1];
            int v = prerequisites[e][0];
            
            Adj[u].push_back(v);
        }
        
        bool no_cycle = true;
        for (int u = 0; u != numCourses && no_cycle; ++u)
            if (vertex_status[u] == non_visited)
                DFS_Visit(u, vertex_status, no_cycle);
        
        if (no_cycle)
            return vector<int>(sorted_vertices.begin(), sorted_vertices.end());
        else
            return {};
    }
};

int main(void)
{
//    vector<vector<int>> pre{{1,0},{2,0},{3,1},{3,2}};
//    vector<vector<int>> pre{{1,0}, {2, 1}, {0, 2}};
    vector<vector<int>> pre{};
    int numCourses = 1;
    Solution sol = Solution();
    
    auto res = sol.findOrder(numCourses, pre);
    
    for (auto v : res)
        cout << v << " ";
    cout << endl;
    
    return 0;
    
}
