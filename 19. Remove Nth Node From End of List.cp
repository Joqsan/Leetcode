#include <iostream>
#include <vector>
#include <deque>

using namespace std;

/*
 
 There is another solution using two pointers
 (described in Leetcode)
 url: https://leetcode.com/problems/remove-nth-node-from-end-of-list/discuss/8812/My-short-C%2B%2B-solution
 
 But is argued that it doesn't produce an improvement
 over the two-pass solution:
 
 Jaltair 224 Last Edit: August 25, 2018 10:08 AM
 
 One pass algorithm doesn't give you an improvement the article claims.
 First method "two passes":
  - Traverse M steps, where M is the length of the list.
  - Traverse K steps to remove Nth element (K = length - N)
 Second method "one pass algorithm":
  - First pointer traverses (M + 1) steps
  - Second pointer traverses K steps
 
 
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int flag = -1;
class Solution
{
public:
    void removeNthFromEnd(ListNode* head, int n)
    {
        deque<ListNode*> q;
        ListNode* traverse = head;
        ListNode anchor(0);
        
        q.push_front(&anchor);
        while (traverse)
        {
            q.push_front(traverse);
            traverse = traverse->next;
        }
        
        // after the loop above the node
        // to be removed in the n-th position
        // of the deque, i.e. in q[n-1]
        // We have to connect the predecessor of
        // q[n-1], located at q[n], with its
        // succesor.
        // If q[n-1] is the head, then has no
        // predecessor and we just have to
        // shift right the list head
        if (q[n] != &anchor)
            q[n]->next = q[n-1]->next;
        else
            head = q[n-1]->next;
        
        traverse = head;
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
    vector<int> l1{1,2,3,4,5};
    int n = 1;
    vector<ListNode*> nodes1;
    
    for (int i = 0; i != l1.size(); ++i)
        nodes1.push_back(new ListNode(l1[i]));
    
    for (int i = 1; i != l1.size(); ++i)
        nodes1[i-1]->next = nodes1[i];
    
    Solution sol = Solution();
    
    sol.removeNthFromEnd(nodes1[0], n);
    
    return 0;
    
}
