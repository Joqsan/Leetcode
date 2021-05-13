#include <queue>
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
    
    int minDepth(TreeNode* root)
    {
        queue<pair<TreeNode*, int>> Q;
        
        Q.push({root, 1});
        
        while (root)
        {
            auto [node, depth] = Q.front();
            Q.pop();
            
            if (!node->left && !node->right)
                return depth;
            
            if (node->left)
                Q.push({node->left, depth+1});
            if (node->right)
                Q.push({node->right, depth+1});
        }
        
        return 0;
    }
};


int main(void)
{
    vector<int> nums{1,2,3,4,5};
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
    
    cout << sol.minDepth(p[0]) << endl;
    
    return 0;
}
