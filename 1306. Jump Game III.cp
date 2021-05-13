#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    bool canReach(vector<int>& arr, int start)
    {
        int N = arr.size();
        vector<bool> visited(N, false);
        queue<int> Q;
        
        visited[start] = true;
        Q.push(start);
        
        while (!Q.empty())
        {
            auto u = Q.front();
            Q.pop();
            
            if (arr[u] == 0)
                return true;
            
            for (auto shift : {arr[u], -arr[u]})
                if (u + shift >= 0  && u + shift < N)
                    if (!visited[u+shift])
                    {
                        visited[u+shift] = true;
                        Q.push(u+shift);
                    }
        }
        
        return false;
    }
};
