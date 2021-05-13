#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;


 struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    
};


class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode*, bool> visited;
        
        ListNode* traverse = headA;
        
        while (traverse)
        {
            visited[traverse] = true;
            traverse = traverse->next;
        }
        
        traverse = headB;
        
        while (traverse && !visited[traverse])
            traverse = traverse->next;
            
        return traverse;
    }
};

int main(void)
{
    vector<int> l1{4,1,8,4,5};
    vector<int> l2{5,6,1,8,4,5};
    
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
    
    auto res = sol.getIntersectionNode(nodes1[0], nodes2[0]);
    
    cout << res->val << endl;
    
    return 0;
    
}
