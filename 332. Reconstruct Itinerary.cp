#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <deque>

using namespace std;

/*
 
 The key here is that
 
 1) One person flying from a specific airport (JFK)
 2) Every ticket has to be used once.
 
 An itinerary is a path.
 
 Assumption from real world: once the person leaves
 an airport S_i, it can only flight from S_i again
 iff along the path he flies back to it.
 
 Condition 2) implies that there is a path where every
 ticket is used. That is, there is a path we every edge is visited.
 That is, it's assumed that there is an eulerian path.
 
 We don't need to find the eulerian path because it's already
 there. We just have to print it.
 
 
 Claim: If p = (JFK, ..., v) is the main initial path, then the
 remaining tickets form cycles. This can be proved by contradiction.
 
 So if when going backward the first vertex we can use to fly to
 an unvisited airport is u (that is p = (JFK, ..., u, ..., v)), then
 there is a cycle leading back to u. This is why using topological sort
 gives the correct answer: when going backwards exploring for possible
 routes the cycles bring us back to where we started the exploration, so
 the relative order of finished vertices is preserved.
 
 */

typedef priority_queue<string, vector<string>, greater<string>> ordered_queue;
class Solution
{
private:
    unordered_map<string, ordered_queue> Adj;
    
public:
    
    void DFS_Visit(const string u, deque<string> &Q)
    {
        while (!Adj[u].empty())
        {
            auto v = Adj[u].top();
            Adj[u].pop();
            DFS_Visit(v, Q);
        }
        
        Q.push_front(u);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        deque<string> Q;
        
        for (auto e : tickets)
            Adj[e[0]].push(e[1]);
        
        DFS_Visit("JFK", Q);
        
        return vector<string>(Q.begin(), Q.end());
        
    }
};


int main(void)
{
    vector<vector<string>> tickets{{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    
    Solution sol = Solution();
    
    auto ans = sol.findItinerary(tickets);
    
    for (auto v : ans)
        cout << v << " ";
    cout << endl;
    
    return 0;
}

