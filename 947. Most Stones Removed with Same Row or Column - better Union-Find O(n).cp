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
 + O(n) for the main loop ==> O(n)
 - Space: O(n)
 
 Difference:
 - We consider each appearing row and colum as elements to be united.
 - In contrast, for the slow solution the elements where considered to be the
    cell position themselves.
 - That's way here we can have n_components = stones.size().
 - To fix this we count the number of components as we discover them (i.e. when
    we try to find their parent for the first time (check code below for find)).
 
 */

class Solution
{
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> sizes;
    int n_components;
    // n unions with m > n finds: O(m*logn)
    int find(int x)
    {
        if (!parent.count(x))
        {
            parent[x] = -1;
            sizes[x] = 1;
            ++n_components;
        }
        
        if (parent[x] == -1)
            return x;
        
        return parent[x] = find(parent[x]);
    }
    
    // union by size. Complexity: O(logn)
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
        
        n_components = 0;
        for (int i = 0; i != N; ++i)
        {
            int fi = find(stones[i][0]);
            int fj = find(~stones[i][1]);
            
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

