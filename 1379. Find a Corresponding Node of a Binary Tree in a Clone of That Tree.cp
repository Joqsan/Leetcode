
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution
{
public:
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        stack<TreeNode*> Q;
        
        Q.push(cloned);
        
        while (!Q.empty())
        {
            auto node = Q.top();
            Q.pop();
            
            if (node->val == target->val)
                return node;
            
            if (node->left)
                Q.push(node->left);
            
            if (node->right)
                Q.push(node->right);
            
        }
        
        return nullptr;
    }
};
