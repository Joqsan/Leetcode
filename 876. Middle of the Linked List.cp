

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode* traverse = head;
        int counter = 0;
        
        while (traverse)
        {
            ++counter;
            traverse = traverse->next;
        }
        
        counter /= 2;
        int i = 1;
        
        traverse = head;
        while (traverse && i < counter)
        {
            traverse = traverse->next;
            ++i;
        }
        
        return traverse;
    }
};
