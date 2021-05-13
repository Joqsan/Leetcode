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
#include <vector>
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next){}
    
};

class Solution
{
public:
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* head;
        
        //find the head of the merge list
        if (!l2 || (l1 && l1->val < l2->val))
            head = l1;
        else
            head = l2;
        
        
        while (l1 && l2)
        {
            while (l1->next && l1->next->val < l2->val)
                l1 = l1->next;
            
            // the first condition is not needed.
            if (l1 && l1->val < l2->val)
            {
                ListNode* detached = l1->next;
                l1->next = l2;
                l1 = detached;
            }
            
            // l1 can be null because detached above can be null
            // if l1 (detached) is null, then all the elements in
            // l1 were traversed, so we need to appen at the end of
            // l1 all the elements of l2, but this was already done
            // above. Hence we can either break or continue.
            if (!l1)
                continue;
            
            // the code below is executed if l1 != nullptr, so
            // no need to check for it.
            while (l2->next && l2->next->val <= l1->val)
                l2 = l2->next;
            
            if (l2 && l2->val <= l1->val)
            {
                ListNode* detached = l2->next;
                l2->next = l1;
                l2 = detached;
            }
        }
        
        return head;
    }
};

int main(void)
{
    vector<int> l1{-9, 3};
    vector<int> l2{5, 7};
    
    vector<ListNode*> nodes1;
    vector<ListNode*> nodes2;
    
    for (int i = 0; i != l1.size(); ++i)
        nodes1.push_back(new ListNode(l1[i]));
    
    for (int i = 1; i != l1.size(); ++i)
        nodes1[i-1]->next = nodes1[i];
    
    for (int i = 0; i != l2.size(); ++i)
        nodes2.push_back(new ListNode(l2[i]));
    
    for (int i = 1; i != l2.size(); ++i)
        nodes2[i-1]->next = nodes2[i];
    
    Solution sol = Solution();
    
    auto res = sol.mergeTwoLists(nodes1[0], nodes2[0]);
    
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    
    return 0;
    
}

