#include <queue>

using namespace std;


/*
 
 Using level traversal (BFS) to connect each
 node on the same level to the right one.
 */

class Node
{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    
    Node(int _val, Node* _left, Node* _right, Node* _next)
    : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution
{
public:
    Node* connect(Node* root)
    {
        queue<Node*> Q;
        
        Q.push(root);
        
        while (!Q.empty())
        {
            Q.push(nullptr);
            int size = Q.size();
            
            for (int i = 0; i != size; ++i)
            {
                auto u = Q.front();
                Q.pop();
                
                if (u)
                {
                    u->next = Q.front();
                    
                    if (u->left)
                        Q.push(u->left);
                    if (u->right)
                        Q.push(u->right);
                }
            }
        }
        
        return root;
    }
};
