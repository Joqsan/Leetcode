#include <cstdlib>
#include <vector>

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
    vector<int> traverse;
    
    void make_traversal(TreeNode* root)
    {
        if (root)
        {
            traverse.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root)
    {
        make_traversal(root);
        return traverse;
    }
};
