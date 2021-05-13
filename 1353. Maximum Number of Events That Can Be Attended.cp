#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;


/*
 Notice that you can only attend one event at any time d.
 
 Return the maximum number of events you can attend.
 
 Key idea:
1) Sort the elements by starting date.
2) Among the events starting on the earliest date, pick/count the
 one ending the earliest.
3) If there are more than one event ending on the same date, just pick
 any of them and ignore the rest.
 
 Complexity:
 - Time: O(n*longn) for sorting + O(d + n*logn) where d = 100000 for checking each possible ending date and for keeping the priority queue.
 - Space: O(n) for the priority queue.
 */


class Solution
{
public:
    int maxEvents(vector<vector<int>>& events)
    {
        // 1) Sort by starting date
        sort(events.begin(), events.end());
        
        // To pick the one ending the earliest we'll
        // use a priority queue
        priority_queue<int, vector<int>, greater<int>> Q;
        int N = events.size();
        int i = 0;
        int res = 0;
        
        for (int start = 0; start != 100000; ++start)
        {
            // Remove all the ignore events not picked
            // below.
            while (!Q.empty() && events[i][0] < start)
                Q.pop();
            
            // for the current earliest day, sort by
            // increasing ending day.
            while (i < N && events[i][0] == start)
                Q.push(events[i++][1]);
            
            // From those that we push, pick and count
            // one of them (if there is any)
            if (!Q.empty())
            {
                Q.pop();
                ++res;
            }
            
            
        }
        
        return res;
    }
};

int main(void)
{
    vector<vector<int>> events{{1,2},{2,3},{3,4}};
    
    Solution sol = Solution();
    
    cout << sol.maxEvents(events) << endl;
    
    return 0;
}
