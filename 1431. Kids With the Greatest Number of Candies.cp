#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
    {
        int N = candies.size();
        vector<bool> ans;
        
        int max = *max_element(candies.begin(), candies.end());
        
        for (auto kid_candies : candies)
            ans.push_back(kid_candies + extraCandies >= max);
        
        return ans;
        
    }
};
