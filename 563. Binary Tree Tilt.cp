#include <cstdlib>

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
    
    int total = 0;
    
    int subtree_sum(TreeNode* root)
    {
        int left_sum = 0;
        int right_sum = 0;
        
        
        if (root->left)
            left_sum = subtree_sum(root->left);
        if (root->right)
            right_sum = subtree_sum(root->right);
        
        total += abs(left_sum - right_sum);
        
        return root->val + left_sum + right_sum;
    }
    
    int findTilt(TreeNode* root)
    {
        if (!root)
            return 0;
        
        subtree_sum(root);
        
        return total;
    }
};
