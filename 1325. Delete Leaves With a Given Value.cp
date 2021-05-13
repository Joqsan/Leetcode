


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
    
    void remove(TreeNode* node, TreeNode* parent, const int &target)
    {
        if (node)
        {
            remove(node->left, node, target);
            remove(node->right, node, target);
            
            if (!node->left && !node->right && node->val == target)
            {
                if (parent->left == node)
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
            }
        }
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target)
    {
        TreeNode* anchor = new TreeNode(0, root, nullptr);
        
        remove(root, anchor, target);
        
        return anchor->left;
    }
};
