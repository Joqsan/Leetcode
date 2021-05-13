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

/*
 
 If a node u is to be removed:
 - Remove it by changing the child pointer of its parent to null.
 - If a child of u is not to be removed, then it's the root of one
    of the trees in the forest.
 
 Complexity:
 - Time: O(n) (for the Pre-order traversal)
 - Space: O(1001 + n) = O(1001)
 */

class Solution
{
public:
    vector<TreeNode*> forest;
    vector<bool> to_remove;
    void traverse(TreeNode* root, TreeNode* parent)
    {
        if (root)
        {
            
            if (to_remove[root->val])
            {
                if(root->left && !to_remove[root->left->val])
                    forest.push_back(root->left);
                
                if(root->right && !to_remove[root->right->val])
                    forest.push_back(root->right);
                
                if (parent)
                {
                    if (parent->left == root)
                        parent->left = nullptr;
                    else
                        parent->right = nullptr;
                }
            }
            
            traverse(root->left, root);
            traverse(root->right, root);
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
    {
        to_remove.resize(1001, false);
        
        for (auto val : to_delete)
            to_remove[val] = true;
        
        TreeNode* anchor = new TreeNode(0, root, nullptr);
        
        to_remove[0] = true;
        traverse(anchor, nullptr);
        
        return forest;
    }
};
