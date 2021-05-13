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

#include <deque>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

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
    void addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        
        ListNode head = ListNode(0);
        ListNode* tail = &head;
        
        div_t result = {0, 0};
        
        while (result.quot > 0 || l1 || l2)
        {
            if (l1)
            {
                result.quot += l1->val;
                l1 = l1->next;
            }
            
            if (l2)
            {
                result.quot += l2->val;
                l2 = l2->next;
            }
            
            result = div(result.quot, 10);
            
            tail->next = new ListNode(result.rem);
            tail = tail->next;
        }
        
        
        ListNode* traverse = head.next;
        while (traverse)
        {
            cout << traverse->val << " ";
            traverse = traverse->next;
        }
        cout << endl;
    }
};

int main(void)
{
    vector<int> l1{2,4,3};
    vector<int> l2{5,6,4};
    
    vector<ListNode*> nodes1;
    vector<ListNode*> nodes2;
    
    for (int i = 0; i != l1.size(); ++i)
        nodes1.push_back(new ListNode(l1[i]));
    
    for (int i = 0; i != l2.size(); ++i)
        nodes2.push_back(new ListNode(l2[i]));
    
    for (int i = 1; i != l1.size(); ++i)
        nodes1[i-1]->next = nodes1[i];
    
    for (int i = 1; i != l2.size(); ++i)
        nodes2[i-1]->next = nodes2[i];
    
    Solution sol = Solution();
    
    sol.addTwoNumbers(nodes1[0], nodes2[0]);
    
    return 0;
    
}
