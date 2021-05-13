#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes)
    {
        unordered_map<int, int> count;
        int ans = 0;
        
        for (auto d : dominoes)
        {
            
            ans += count[min(d[0], d[1]) * 10 + max(d[0], d[1])]++;
        }
        
        return ans;
    }
};

int main(void)
{
    vector<vector<int>> dominoes{{1,2},{2,1},{2,1},{2,1}, {2,1}, {2,1}, {2,1}, {2,1}, {2,1}, {2,1}};
    
    Solution sol = Solution();
    
    cout << sol.numEquivDominoPairs(dominoes) << endl;
    
    return 0;
}
