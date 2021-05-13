
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
    void reverseList(ListNode* head)
    {
        ListNode* left_next = nullptr;
        
        while (head)
        {
            //Get the right next child
            ListNode* right_next = head->next;
            
            //Make the left node the child
            //(this break the list in two)
            head->next = left_next;
            
            // Make the current head the
            // next left child for the next
            // node
            left_next = head;
            
            // Repeat the process for the next
            // right node
            head = right_next;
        }
        
        ListNode* traverse = left_next;
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
    vector<int> l1{};
    
    vector<ListNode*> nodes1;
    
    for (int i = 0; i != l1.size(); ++i)
        nodes1.push_back(new ListNode(l1[i]));
    
    for (int i = 1; i != l1.size(); ++i)
        nodes1[i-1]->next = nodes1[i];
    
    Solution sol = Solution();
    
    sol.reverseList(nodes1[0]);
    
    return 0;
    
}
