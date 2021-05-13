#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
    vector<vector<int>> modes;
    unordered_map<int, int> counter;
    
    void traverse(TreeNode* root)
    {
        if (root)
        {
            ++counter[root->val];
            
            if (counter[root->val] > modes.size())
                modes.push_back({root->val});
            else
                modes[counter[root->val]-1].push_back(root->val);
            
            traverse(root->left);
            traverse(root->right);
        }
    }
    
    vector<int> findMode(TreeNode* root)
    {
        traverse(root);
        
        return modes[modes.size()-1];
        
    }
};

