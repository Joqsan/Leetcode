#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
 I can think of two solutions:
 
 1)
 - reverse l1
 - reverse l2
 - sum and generate the new link list at the same time.
 
 Complexity:
 - Time: O(n1 + n2 + max(n1, n2)) = O(n1 + n2).
 - Space: O(n1 + n2) if generating a new ll. O(1) if using the largest ll between l1 and l2.
 
 
 2)
 - Stack l1.
 - Stack l2.
 - sum and generate the new link list at the same time.
 
 Complexity:
 - Time: O(n1 + n2).
 - Space: O(n1 + n2)
 */

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        stack<int> s1;
        stack<int> s2;
        
        while (l1 || l2)
        {
            if (l1)
            {
                s1.push(l1->val);
                l1 = l1->next;
            }
            
            if (l2)
            {
                s2.push(l2->val);
                l2 = l2->next;
            }
        }
        
        
        int offset = 0;
        ListNode* last = nullptr;
        while (!s1.empty() || !s2.empty() || offset)
        {
            int sum = offset;
            
            if (!s1.empty())
                sum += s1.top(); s1.pop();
            
            if (!s2.empty())
                sum += s2.top(); s2.pop();
            
            ListNode* next = new ListNode(sum % 10, last);
            last = next;
            
            offset = sum / 10;
            
        }
        
        return last;
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
