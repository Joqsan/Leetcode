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
    void insertionSortList(ListNode* head)
    {
        ListNode* key = head->next;
        ListNode* prev_key = head;
        
        while (key)
        {
            ListNode* traverse = head;
            ListNode* new_parent = nullptr;
            
            while (traverse != key && traverse->val < key->val)
            {
                new_parent = traverse;
                traverse = traverse->next;
            }
            
            if (traverse != key)
            {
                prev_key->next = key->next;
                
                if (new_parent)
                    new_parent->next = key;
                else
                    head = key;
                
                key->next = traverse;
                
                key = prev_key->next;
            }
            else
            {
                prev_key = key;
                key = key->next;
            }
        }
        
        
        ListNode* tr = head;
        while (tr)
        {
            cout << tr->val << " ";
            tr = tr->next;
        }
        cout << endl;
    }
};

int main(void)
{
    vector<int> l1{-1,5,3,4,0, -1};
    
    vector<ListNode*> nodes1;
    
    for (int i = 0; i != l1.size(); ++i)
        nodes1.push_back(new ListNode(l1[i]));
    
    for (int i = 1; i != l1.size(); ++i)
        nodes1[i-1]->next = nodes1[i];
    
    Solution sol = Solution();
    
    sol.insertionSortList(nodes1[0]);
    
    return 0;
    
}
