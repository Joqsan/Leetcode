




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
    int curr_height = -1;
    int curr_sum = 0;
    
    void sum(TreeNode* node, int height)
    {
        if (node)
        {
            if (!node->left && !node->right)
            {
                if (curr_height == height)
                    curr_sum += node->val;
                else if (curr_height < height)
                {
                    curr_height = height;
                    curr_sum = node->val;
                }
            }
            
            sum(node->left, height+1);
            sum(node->right, height+1);
        }
    }
    int deepestLeavesSum(TreeNode* root)
    {
        sum(root, 0);
        
        return curr_sum;
    }
};
