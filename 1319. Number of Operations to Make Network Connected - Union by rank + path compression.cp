#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 
 Facts:
 1) If there are n computers, then at least
 n-1 edges are required to make all computers
 connected (a tree). So the minimum nurember is
 n-1.
 
 2) Suppose that there are m group of computers
 disconnected from each other (computer within a
 group are connected). This falls back to the original
 problem, with m edges. Therefore the minum number of
 edges requires to connect them is m-1.
 
 Find the number of connected components. Different
 connected components are not reachable from one other,
 so this allows us to find those m groups of connected
 components. We can find the components with Union-Find
 or Kosaraju algorithm.
 
 Below Union by rank is implemented along with path
 compression.
 
 Final Time Complexity: O(m*alpha(n));
 
 where alpha(n) = min{k | A_k(1) >= n}
 
 is the inverse of the Ackermann function
 */

class Solution
{
public:
    vector<int> repr;
    vector<int> size;
    
    // Path Compression
    int find(int x)
    {
        if (repr[x] == -1)
            return x;
        
        return repr[x] = find(repr[x]);
    }
    
    // Union by rank
    void unite(int f_a, int f_b)
    {
        if (size[f_a] < size[f_b])
            swap(f_a, f_b);
        
        size[f_a] += size[f_b];
        repr[f_b] = f_a;
    }
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        if (connections.size() < n-1)
            return -1;
        
        size.resize(n, 0);
        repr.resize(n, -1);
        int n_components = n;
        
        for (auto e : connections)
        {
            int f_a = find(e[0]);
            int f_b = find(e[1]);
            
            if (f_a != f_b)
            {
                unite(f_a, f_b);
                --n_components;
            }
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

