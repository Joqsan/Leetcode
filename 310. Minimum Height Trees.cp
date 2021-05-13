#include <vector>
#include <iostream>
#include <deque>
#include <list>
#include <numeric>

using namespace std;

class Solution
{
private:
    vector<list<int>> Adj;
public:
    
    Solution(void) = default;

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        if (n < 2)
        {
            vector<int> centroids(n);
            iota(centroids.begin(), centroids.end(), 0);
            return centroids;
        }
        
        Adj.resize(n);
        vector<bool> in_deque(n, false);
        
        for (auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }
        
        deque<int> leaves;
        for (int u = 0; u != n; ++u)
            if (Adj[u].size()==1)
            {
                in_deque[u] = true;
                leaves.push_back(u);
            }
        
        int remaining_nodes = n;
        while (remaining_nodes > 2)
        {
            remaining_nodes -= leaves.size();
            
            deque<int> new_leaves;
            while (!leaves.empty())
            {
                int u = leaves.front();
                leaves.pop_front();
                
                for (auto v : Adj[u])
                {
                    Adj[v].remove(u);
                    
                    if (Adj[v].size() == 1)
                    {
                        in_deque[v] = true;
                        new_leaves.push_back(v);
                    }
                }
            }
            
            leaves = new_leaves;
        }
        
        return vector<int>(leaves.begin(), leaves.end());
    }
};


int main(void)
{
//    vector<vector<int>> edges{{3,0},{3,1},{3,2},{3,4},{5,4}};
    vector<vector<int>> edges{{1, 0}, {1,2}, {1,3}};
    int n = 4;
    
    Solution sol = Solution();
    
    auto res = sol.findMinHeightTrees(n, edges);
    
    for (auto v : res)
        cout << v << " ";
    cout << endl;
    
    return 0;
}
