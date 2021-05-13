#include <vector>
#include <iostream>
#include <queue>

using namespace std;
/*
 // Definition for a Node.
 class Node {
 public:
 int val;
 vector<Node*> children;
 
 Node() {}
 
 Node(int _val) {
 val = _val;
 }
 
 Node(int _val, vector<Node*> _children) {
 val = _val;
 children = _children;
 }
 };
 */

class Node {
public:
    int val;
    vector<Node*> children;
    
    Node() {}
    
    Node(int _val) {
        val = _val;
    }
    
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution
{
public:
    int maxDepth(Node* root)
    {
        int max_depth = 0;
        
        if (!root)
            return max_depth;
        
        queue<pair<int, Node*>> Q;
        Q.push({1, root});
        
        
        while (!Q.empty())
        {
            auto [u_depth, u] = Q.front();
            Q.pop();
            max_depth = u_depth;
            
            for (auto v : u->children)
                if (v)
                    Q.push({u_depth+1, v});
        }
        
        return max_depth;
    }
};
