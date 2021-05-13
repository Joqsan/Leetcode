


 struct ListNode {
         int val;
         ListNode* next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode* next) : val(x), next(next) {}
     };

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* before = head;
        ListNode* curr = nullptr;
        
        if (head)
            curr = head->next;
        
        while (curr)
        {
            if (before->val == curr->val)
            {
                before->next = curr->next;
                curr = curr->next;
            }
            else
            {
                before = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};
