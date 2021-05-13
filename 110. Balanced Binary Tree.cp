#include <algorithm>

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
    
    int height(TreeNode* root)
    {
        if (!root)
            return 0;
        
        int depth = 0;
        
        depth = max(depth, height(root->left));
        depth = max(depth, height(root->right));
        
        return depth + 1;
    }
    
    bool isBalanced(TreeNode* root)
    {
        if (!root)
            return true;
        
        int depth_l = height(root->left);
        int depth_r = height(root->right);
        
        if (abs(depth_r - depth_l) > 1)
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
        
    }
};
