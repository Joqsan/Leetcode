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
    
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        queue<TreeNode*> Q;
        int sum = 0;
        
        Q.push(root);
        
        while (!Q.empty())
        {
            auto node = Q.front();
            Q.pop();
            
            if (low <= node->val && node->val <= high)
                sum += node->val;
            
            if (node->left)
                Q.push(node->left);
            if (node->right)
                Q.push(node->right);
        }
        
        return sum;
    }
};


int main(void)
{
    vector<int> nums{10,5,15,3,7,-1,18};
    int low = 7;
    int high = 15;
    
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
    
    cout << sol.rangeSumBST(p[0], low, high) << endl;
    
    return 0;
}
