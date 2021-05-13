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
        
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        
        int overflow = 0;
        
        ListNode* prev = nullptr;
        ListNode* head;
        while (t1 && t2)
        {
            ListNode* node = new ListNode((t1->val + t2->val + overflow) % 10);
            
            if (prev)
                prev->next = node;
            else
                head = node;
            
            prev = node;
            overflow = (t1->val + t2->val + overflow) / 10;
            
            t1 = t1->next;
            t2 = t2->next;
        }
        
        while (t1)
        {
            ListNode* node = new ListNode((t1->val + overflow) % 10);
            
            prev->next = node;
            prev = node;
            
            overflow = (t1->val + overflow) / 10;
            
            t1 = t1->next;
        }
        
        while (t2)
        {
            ListNode* node = new ListNode((t2->val + overflow) % 10);
            
            prev->next = node;
            prev = node;
            
            overflow = (t2->val + overflow) / 10;
            
            t2 = t2->next;
        }
        
        if (overflow)
        {
            ListNode* node = new ListNode(overflow);
            prev->next = node;
        }
        
        
        ListNode* traverse = head;
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
