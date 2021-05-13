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


class Solution
{
public:
    vector<int> arr;
    
    void Traversal(TreeNode* root)
    {
        if (root)
        {
            inorderTraversal(root->left);
            arr.push_back(root->val);
            inorderTraversal(root->right);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root)
    {
        
        Traversal(root);
        
        return arr;
    }
};

int main(void)
{
    vector<int> nums{1,-1,2,3};
    vector<TreeNode*> p;
    Solution sol = Solution();
    
    for (int i = 0; i != nums.size(); ++i)
    {
        p.push_back(new TreeNode(nums[i]));
    }
    
    for (int i = 0; i != nums.size()/2+1; ++i)
    {
        if (nums[i] != -1)
        {
            int left = i + 1;
            int right = i + 2;
            
            if (left < nums.size() && nums[left] != -1)
                p[i]->left = p[left];
            
            if (right < nums.size() && nums[right] != -1)
                p[i]->right = p[right];
        }
    }
    
    auto res =  sol.inorderTraversal(p[0]);
    
    for (auto v : res)
        cout << v << " ";
    cout << endl;
    
    return 0;
}
