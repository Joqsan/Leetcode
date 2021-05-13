#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;


/**
 * Definition for a binary tree TreeNode.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


struct TreeNode {
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
    Solution(void) = default;
    vector<double> averageOfLevels(TreeNode* root)
    {
        if (!root)
            return {};
        
        vector<vector<int>> levels;
        queue<pair<TreeNode*, int>> Q;
        
        Q.push({root, 0});
        
        while (!Q.empty())
        {
            auto [pnode, depth] = Q.front();
            Q.pop();
            
            if (levels.size() < depth + 1)
                levels.push_back({});
            
            levels[depth].push_back(pnode->val);
            
            if (pnode->left)
                Q.push({pnode->left, depth+1});
            if (pnode->right)
                Q.push({pnode->right, depth+1});
        }
        
        vector<double> ans(levels.size());
        for (int i = 0; i != levels.size(); ++i)
            ans[i] = accumulate(levels[i].begin(), levels[i].end(), 0.0) / levels[i].size();
        
        return ans;
    }
};

int main(void)
{
    vector<int> nums{3,9,20,-1,-1,15,7};
    //    vector<int> nums{16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
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
    
    auto result =  sol.averageOfLevels(p[0]);
    
    for (auto v : result)
        cout << v << " ";
    cout << endl;
    
    return 0;
}




