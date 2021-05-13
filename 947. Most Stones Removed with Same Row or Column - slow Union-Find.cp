#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 Find the number of connected components: those
 stones sharing the same row and/or the same col.
 
 From each component we can remove stones until
 there is just one left.
 
 If there are n connected components, then
 at the end there'll be n stones left (we can no longer remove).
 
 So max of removed stones = total stones - n
                          = total stones - n_components
 
 
 Approach: Union-Find.
 Complexity:
 - Time: O(alpha(n)) amortized for Union-Find with path compression and union-by-size
        + O(n^2) for the main loop ==> O(n^2)
 - Space: O(n)
 
 */

class Solution
{
public:
    vector<int> parent;
    vector<int> sizes;
    int find(int x)
    {
        if (parent[x] == -1)
            return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void unite(int fa, int fb)
    {
        if (sizes[fa] < sizes[fb])
            swap(fa, fb);
        
        sizes[fa] += sizes[fb];
        parent[fb] = fa;
    }
    
    
    int removeStones(vector<vector<int>>& stones)
    {
        int N = stones.size();
        
        parent.resize(N, -1);
        sizes.resize(N, 1);
        
        vector<int> parent(N, -1);
        vector<int> sizes(N, 0);
        
        int n_components = N;
        for (int i = 0; i != N; ++i)
            for (int j = 0; j != N; ++j)
                if (i != j)
                    if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    {
                        int fi = find(i);
                        int fj = find(j);
                        
                        if (fi != fj)
                        {
                            unite(fi, fj);
                            --n_components;
                        }
                    }
        
        return N - n_components;
    }
};

int main(void)
{
    vector<vector<int>> stones{{0,1},{1,1},{1,2},{2,2},{2,3},{3,1}};
    
    Solution sol = Solution();
    
    cout << sol.removeStones(stones) << endl;
    
    return 0;
}
