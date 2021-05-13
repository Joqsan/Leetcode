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

/*
 
 modes[i-1] - counter all the key nodes appearing i times in the tree.
 
 Thus, in modes[modes.size()-1] are the current modes in the tree, so
 the mode appear modes.size() in the tree.
 
 Anytime the mode of a node is > modes.size() we update modes.
 
 The else part can be change to else if (counter[root->val] == modes.size()),
 since there is no need push_back less frequent nodes, because they won't be
 part of the final solution.
 
 
 The is a way to do it without the map:
 
 - One tree traversal to find the total number of nodes modeCount having the maximum frequency maxCount.
 - Initialize the resulting vector ans with size modeCount.
 - Perform second traversal putting in ans each node having a frequency of maxCount.
 - More details: https://leetcode.com/problems/find-mode-in-binary-search-tree/discuss/98101/Proper-O(1)-space
 */

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

