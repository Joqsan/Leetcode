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

/*
 
 | 1 | 2 | 3 | 6 | 5 | 7 | 4 | 9 |
 
 invert from 2 to 5
 
 | 1 | 5 | 6 | 3 | 2 | 7 | 4 | 9 |
 
 
 - The invertion for elements within 2-5 is
 carried out as in the easier case.
 - The thing is that we have also to connect 1->5 and 2->7, that is
 One before the first inverted element -> the last element inverted
 The first inverted element -> one past the last inverted element.
 
 Complexity:
 - Time: O(n)
 - Space: O(1).
 
 */

class Solution
{
public:
    void reverseBetween(ListNode* head, int left, int right)
    {
        ListNode* traverse = head;
        ListNode* before = new ListNode(0, head);
        
        int pos = 1;
        
        // Find the first element to be inverted
        while (pos < left)
        {
            ++pos;
            before = traverse;
            traverse = traverse->next;
        }
        
        
        // Invert element up to the last one
        ListNode* after;
        ListNode* left_next = nullptr;
        while (pos <= right)
        {
            ++pos;
            after = traverse->next;
            traverse->next = left_next;
            left_next = traverse;
            traverse = after;
        }
        // when pos == right + 1
        // traverse is one past the last element that has to be inverted
        // left_next is the last element to be inverted
        // We make the reconnection so as to keep the link list connected
        before->next->next = traverse;
        before->next = left_next;
        
        
        // If left == 1 then the head was updated. Otherwise is the same
        traverse = (left == 1) ? before->next : head;
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
    vector<int> l1{1,2,3,6,5,7,4,9};
    int left = 1;
    int right = 8;
    
    vector<ListNode*> nodes1;
    
    for (int i = 0; i != l1.size(); ++i)
        nodes1.push_back(new ListNode(l1[i]));
    
    for (int i = 1; i != l1.size(); ++i)
        nodes1[i-1]->next = nodes1[i];
    
    Solution sol = Solution();
    
    sol.reverseBetween(nodes1[0], left, right);
    
    return 0;
    
}
