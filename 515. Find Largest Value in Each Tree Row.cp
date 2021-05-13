#include <algorithm>
#include <vector>
#include <queue>

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
 Idea:
 - Do BFS on the tree.
 - Find all nodes at the current level.
 - While popping all the node from the current level, check
 for the one with the largest value.
 
 Complexity:
 - Time: O(n).
 - Space: O(n + h) (queue + vector with answer). For a completely balanced tree h = lg(n+1). Worst case: O(n + n) = O(n).
 
 */

class Solution
{
public:
    vector<int> largestValues(TreeNode* root)
    {
        queue<TreeNode*> Q;
        vector<int> res;
        
        if (!root)
            return {};
        
        Q.push(root);
        
        while (!Q.empty())
        {
            int level_size = Q.size();
            int level_max = INT32_MIN;
            
            for (int i = 0; i != level_size; ++i)
            {
                TreeNode* u = Q.front();
                Q.pop();
                
                level_max = max(level_max, u->val);
                
                if (u->left)
                    Q.push(u->left);
                
                if (u->right)
                    Q.push(u->right);
            }
            
            res.push_back(level_max);
        }
        
        return res;
    }
};
