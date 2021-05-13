#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 Idea:
 
 We see that the time it takes a node u to receive a signal
 from k is the shortest path from k to u.
 
 Therefore, time it takes for all nodes to receive the signal
 is equal to the time it takes the node farthest from the source k
 
 The shortest path from k to every node can be found using Dijkstra's
 Algorithm.
 
 The farthest node from k is the one having the path of largest weight,
 among all shortest paths.
 
 This can be found after finding all shortest path from k.
 
 Complexity:
 - Time: O(E*logE) since (there will be at most E elements in the queue, which
 means that extract-min will take at most logE time).
 - Space: O(V + E), we use adjacency list.
 */

typedef pair<int, int> pair_;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<bool> visited(n+1, false);
        vector<vector<pair_>> Adj(n+1);
        vector<int> d(n+1, INT32_MAX);
        priority_queue<pair_, vector<pair_>, greater<pair_>> Q;
        
        int counter = 0;
        
        for (auto edge : times)
            Adj[edge[0]].push_back({edge[1], edge[2]});
        
        d[k] = 0;
        Q.push({0, k});
        
        while (!Q.empty())
        {
            auto [key, u] = Q.top();
            Q.pop();
            
            if (visited[u])
                continue;
            
            visited[u] = true;
            ++counter;
            
            for (auto dest : Adj[u])
            {
                int v = dest.first;
                int w = dest.second;
                    
                if (!visited[v] && d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;
                    Q.push({d[v], v});
                }
            }
            
        }
        
        if (counter != n)
            return -1;
        
        int ans = 0;
        for (int u = 1; u != n+1; ++u)
            ans = max(ans, d[u]);
        
        return ans;
        
    }
};

int main(void)
{
    vector<vector<int>> times{{1,2,1}};
    int n = 2;
    int k = 1;
    
    Solution sol = Solution();
    
    cout << sol.networkDelayTime(times, n, k) << endl;
    
    return 0;
}
