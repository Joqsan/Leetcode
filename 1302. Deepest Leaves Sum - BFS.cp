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
 Keep track of maximum height so far.
 If maximum height is reached by some leaves, then
 add its value to the sum.
 
 If the maximum height is surpassed, then reset the
 sum and update de maximum height.
 
 Complexity:
 
 - Time: O(n).
 - Space: O(n).
 */

class Solution
{
public:
    
    int deepestLeavesSum(TreeNode* root)
    {
        int sum = 0;
        queue<TreeNode*> Q;
        
        Q.push(root);
        
        while (!Q.empty())
        {
            // We begin a new level, so reset the sum.
            sum = 0;
            for (int i = 0; i != Q.size(); ++i)
            {
                auto node = Q.front();
                Q.pop();
                
                sum += node->val;
                
                // Pushing left and right child doesn't
                // affect the level size (i)
                if (node->left)
                    Q.push(node->left);
                
                if (node->right)
                    Q.push(node->right);
            }
        }
        
        return sum;
    }
};
