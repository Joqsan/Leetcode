#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

/*
 
 (a+1)/(b+1) = a/b + t
 t = (a+1)/(b+1) - a/b
 
 Find the class with the ratio that gives
 the biggest t and add the current student
 to that class.
 
 After updating the best-ratio class can be
 a different one. So again find that class.
 
 We do this using a priority queue (max heap)
 
 Complexity: Let n = classes.size and m = extraStudents
 - Building Heap: O(n)
 - We extract the max m times, so max_heapify is called m
   times. max_heapify: O(logn) --> O(m*logn)
 
 Total complexity: O(n + m*logn)
 
 */

typedef pair<int, int> curr_class;
class Solution
{
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
    {
        int N = classes.size();
        
        
        auto profit = [&](double passed, double total)
        {
            return (passed + 1) / (total + 1) - passed / total;
        };
        
        //Make heap
        priority_queue<pair<double, curr_class>> Q;
        double total_ratio = 0;
        for (auto c : classes)
        {
            total_ratio += (double) c[0] / c[1];
            Q.push({profit(c[0], c[1]), {c[0], c[1]}});
        }
        
        while (extraStudents--)
        {
            auto [max_profit, c] = Q.top();
            Q.pop();
            
            total_ratio += max_profit;
            Q.push({profit(c.first+1, c.second+1), {c.first+1, c.second+1}});
        }
        
        return 1.0/N * total_ratio;
        
    }
};

int main(void)
{
    vector<vector<int>> classes{{1,2},{3,5},{2,2}};
    int extra = 2;
    
    Solution sol = Solution();
    
    cout << sol.maxAverageRatio(classes, extra) << endl;
    
    return 0;
}

