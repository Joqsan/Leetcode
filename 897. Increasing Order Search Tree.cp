


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
 - Transform in linked list the left_subtree + root.
    - Once done this, root_left has to be set to null.
    - We have to return the new head
 - Transform in linked list the right_subtree + tail.
    - The new head here will be the new right child of root.
 - If root happens to be null, then we discard that part of the LL.
 
 Complexity:
 
 - Time: O(n).
 - Space: O(h).
 
 */

class Solution
{
public:
            
    TreeNode* increasingBST(TreeNode* root, TreeNode* next= nullptr)
    {
        if (!root)
            return next;
        
        TreeNode* new_head = increasingBST(root->left, root);
        root->left = nullptr;
        root->right = increasingBST(root->right, next);
        
        return new_head;
    }
};
