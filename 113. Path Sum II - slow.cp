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
    vector<vector<int>> paths;
    
    void find_path(TreeNode* root, int targetSum, vector<int> curr_path)
    {
        if (!root)
            return;
        
        curr_path.push_back(root->val);
        
        if (!root->left && !root->right && root->val == targetSum)
            paths.push_back(curr_path);
        
        find_path(root->left, targetSum - root->val, curr_path);
        find_path(root->right, targetSum - root->val, curr_path);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<int> curr_path;
        find_path(root, targetSum, curr_path);
        
        return paths;
    }
};
