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
    
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        
        while (root)
        {
            if (!root->left)
            {
                ans.push_back(root->val);
                root = root->right;
            }
            else
            {
                // find predecessor of rootent
                // node in the inorder traversal
                TreeNode* pred = root->left;
                
                // condition pred->right != root is required
                // in order to avoid falling into an infinite loop
                while (pred->right && pred->right != root)
                    pred = pred->right;
                
                // if we haven't threaded curr to the right child of
                // predecessor, then link, print and proceed to left
                // subtree
                if (!pred->right)
                {
                    pred->right = root;
                    root = root->left;
                }
                else
                {
                    ans.push_back(root->val);
                    pred->right = nullptr;
                    root = root->right;
                }
            }
            
        }
        
        return ans;
    }
};
