#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes)
    {
        map<pair<int, int>, int> count;
        int counter = 0;
        
        for (auto dom : dominoes)
        {
            int a = dom[0];
            int b = dom[1];
            
            if (a > b)
                swap(a, b);
            
            if (count[{a, b}])
                ++count[{a, b}];
            else
                count[{a, b}] = 1;
        }
        
        for (auto [dom, n] : count)
            counter += n * (n-1) / 2;
        
        return counter;
    }
};

int main(void)
{
    vector<vector<int>> dominoes{{1,2},{2,1},{2,1},{2,1}, {2,1}, {2,1}, {2,1}, {2,1}, {2,1}, {2,1}};
    
    Solution sol = Solution();
    
    cout << sol.numEquivDominoPairs(dominoes) << endl;
    
    return 0;
}
