#include <vector>
#include <iostream>

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


class Solution {
public:
    bool checkBST(TreeNode* root, long min, long max)
    {
        if (!root)
            return true;
        
        if (min < root->val && root->val < max)
            return checkBST(root->left, min, root->val) && checkBST(root->right, root->val, max);
        else
            return false;
    }
    bool isValidBST(TreeNode* root)
    {
        return checkBST(root, LONG_MIN, LONG_MAX);
    }
};

int main(void)
{
    vector<int> nums{2,1,3};
    vector<TreeNode*> p;
    Solution sol = Solution();
    
    for (int i = 0; i != nums.size(); ++i)
    {
        if (nums[i] != -1)
            p.push_back(new TreeNode(nums[i]));
    }
    
    for (int i = 0; i != nums.size()/2; ++i)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        p[i]->left = p[left];
        p[i]->right = p[right];
    }
    
    cout << sol.isValidBST(p[0]) << endl;
}
