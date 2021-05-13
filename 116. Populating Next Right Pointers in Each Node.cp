


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
    
    void unite(Node* left, Node*right)
    {
        if (left)
        {
            left->next = right;
            
            unite(left->left, left->right);
            unite(left->right, right->left);
            unite(right->left, right->right);
        }
    }
    Node* connect(Node* root)
    {
        if (root)
            unite(root->left, root->right);
        
        return root;
    }
};
