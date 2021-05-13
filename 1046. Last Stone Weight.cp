#include <vector>
#include <queue>

using namespace std;


/*
 Key:
 
 - Use a priority queue the retrieve the 2 heaviest stones, x and y
 - if x == y, then both are destroyed and repeat.
 - if x - y > 0, then we push x-y on the the queue.
 - The process is repeated.
 - If the queue has one element, return its value.
 
 Complexity:
 - Time: O(n) to build max head + O(n*logn) to retrieve the max (twice) and push the difference ==> O(n*logn)
 - Space: O(n)
 */
class Solution
{
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> Q;
        
        for (auto a : stones)
            Q.push(a);
        
        
        while (!Q.empty())
        {
            if (Q.size() == 1)
                return Q.top();
            
            int max1 = Q.top(); Q.pop();
            int max2 = Q.top(); Q.pop();
            
            if (max1 > max2)
                Q.push(max1 - max2);
        }
        
        return 0;
    }
};
