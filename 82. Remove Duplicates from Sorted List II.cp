


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
        ListNode* start = new ListNode(-100, head);
        ListNode* before = head;
        ListNode* curr = nullptr;
        
        if (head)
            curr = head->next;
        
        while (curr)
        {
            while (curr && before->val != curr->val)
            {
                start = before;
                before = curr;
                curr = curr->next;
            }
            
            while (curr && before->val == curr->val)
            {
                before = curr;
                curr = curr->next;
            }
            
            if (start->next != before)
            {
                start->next = curr;
                
                if (head->val == before->val)
                    head = curr;

                before = curr;
                
                if (curr)
                    curr = curr->next;
            }
        }
        
        return head;
    }
};
