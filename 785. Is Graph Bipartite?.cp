#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        int N = graph.size();
        vector<int> color(N, -1); // color 0 - black, color 1 - white
        
        for (int u = 0; u != N; ++u)
            if (graph[u].size() && color[u] == -1)
            {
                color[u] = 0;
                queue<int> Q;
                
                Q.push(u);
                
                while (!Q.empty())
                {
                    auto w = Q.front();
                    Q.pop();
                    
                    for (auto v : graph[w])
                    {
                        if (color[v] == -1)
                        {
                            color[v] = color[w]^1;
                            Q.push(v);
                        }
                        else if (color[v] != (color[w]^1))
                            return false;
                    }
                }
            }
        
        return true;
        
    }
};

int main(void)
{
    vector<vector<int>> graph{{}};
    
    Solution sol = Solution();
    
    cout << int(sol.isBipartite(graph)) << endl;
    
    return 0;
}
