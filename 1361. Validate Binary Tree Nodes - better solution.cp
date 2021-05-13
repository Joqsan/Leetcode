#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/*
 Idea:
 
 Better solution:
 
 If there is a root, then it has in-degree = 0.
 First find that root.
 
 If found, BFS from the root checking if all n
 nodes are 1) reachable and 2) visited just once.
 
 
 Complexity:
 - Time: O(n)
 - Space: O(n).
 */




class Solution
{
public:
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild)
    {
        
        vector<int> in_degree(n, 0);
        
        // count each node's in-degree
        for (int u = 0; u != n; ++u)
        {
            if (leftChild[u] != -1 && ++in_degree[leftChild[u]] > 1)
                return false;
            
            if (rightChild[u] != -1 && ++in_degree[rightChild[u]] > 1)
                return false;
        }
        
        // find the root.
        int root = -1;
        for (int u = 0; u != n; ++u)
            if (in_degree[u] == 0)
            {
                if (root == -1)
                    root = u;
                else
                    return false;
            }
        
        // If there is no root. this happens
        // when there are no nodes with in-degree 0,
        // that is, when the whole graph is solely
        // composed one or multiple cycles
        if (root == -1)
            return false;
        
        queue<int> Q;
        vector<bool> visited(n, false);
        
        Q.push(root);
        int counter = 0;
        
        while (!Q.empty())
        {
            auto u = Q.front();
            Q.pop();
            ++counter;
            
            visited[root] = true;
            
            if (leftChild[u] != -1)
            {
                if (!visited[leftChild[u]])
                    Q.push(leftChild[u]);
                else
                    return false;
            }
            
            if (rightChild[u] != -1)
            {
                if (!visited[rightChild[u]])
                    Q.push(rightChild[u]);
                else
                    return false;
            }
        }
        
        return counter == n;
    }
};

int main(void)
{
    vector<int> left{1,-1,3,-1};
    vector<int> right{2,-1,-1,-1};
    int n = 4;
    
    Solution sol = Solution();
    
    cout << int(sol.validateBinaryTreeNodes(n, left, right)) << endl;
    
    return 0;
}
