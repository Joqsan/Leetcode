/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

/*
 Idea:
 
 Given the current root and head, check if we can match the
 whole linked list (ll) downwards.
 
 If not we have to repeat the same process from the beginning of ll
 but with the left and right subtrees until we reach a leaf.
 
 If a leaf was reachable, then we weren't able to traverse the whole ll,
 so we return false.
 
 Complexity:
 - Time: O(N).
 - Space: O(h).
 */

class Solution
{
public:
    ListNode* original;
    bool traverse(ListNode* head, TreeNode* root)
    {
        if (root && head)
        {
            if (root->val == head->val)
                return traverse(head->next, root->left) || traverse(head->next, root->right);
            else
                return false;
        }
        else if (!head)
            return true;
        else
            return false;
    }
    
    
    bool isSubPath(ListNode* head, TreeNode* root)
    {
        if (root && head)
        {
            if (traverse(head, root))
                return true;
            else
                return isSubPath(head, root->left) || isSubPath(head, root->right);
        }
        else
            return false;
        
    }
};
